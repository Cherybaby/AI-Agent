import { access, mkdir, readdir, readFile, writeFile } from "node:fs/promises";
import { execFile as execFileCallback } from "node:child_process";
import path from "node:path";
import process from "node:process";
import { promisify } from "node:util";

import { Client } from "@modelcontextprotocol/sdk/client/index.js";
import { StdioClientTransport } from "@modelcontextprotocol/sdk/client/stdio.js";

const DEFAULT_FEISHU_WEBHOOK =
  "https://open.feishu.cn/open-apis/bot/v2/hook/138fd2f9-73e9-4e0b-9abb-34a749ac3950";
const SKILLS_DIR = path.join(process.cwd(), "skills");
const execFile = promisify(execFileCallback);

// Public Zhihu hot-list mirror; works without login/cookie.
const ZHIHU_PUBLIC_HOTLIST_URL = "https://60s.viki.moe/v2/zhihu";

function getArg(flag, fallback = "") {
  const index = process.argv.indexOf(flag);
  if (index === -1) {
    return fallback;
  }

  return process.argv[index + 1] || fallback;
}

async function loadDotEnvFile() {
  const envPath = path.join(process.cwd(), ".env");

  try {
    const content = await readFile(envPath, "utf8");
    const lines = content.split(/\r?\n/);

    for (const rawLine of lines) {
      const line = rawLine.trim();
      if (!line || line.startsWith("#")) {
        continue;
      }

      const eqIndex = line.indexOf("=");
      if (eqIndex <= 0) {
        continue;
      }

      const key = line.slice(0, eqIndex).trim();
      let value = line.slice(eqIndex + 1).trim();

      if (
        (value.startsWith('"') && value.endsWith('"')) ||
        (value.startsWith("'") && value.endsWith("'"))
      ) {
        value = value.slice(1, -1);
      }

      if (!process.env[key]) {
        process.env[key] = value;
      }
    }
  } catch (error) {
    if (error && error.code === "ENOENT") {
      return;
    }

    throw error;
  }
}

function cookieSafetyWarning(cookieValue, expiresAtValue) {
  if (!cookieValue) {
    return "Zhihu cookie is missing. Set ZHIHU_COOKIE in .env to improve access success.";
  }

  if (!/z_c0=|d_c0=|SESSIONID=/i.test(cookieValue)) {
    return "ZHIHU_COOKIE does not include z_c0/d_c0/SESSIONID; Zhihu may limit anonymous hot access.";
  }

  if (!expiresAtValue) {
    return "Set ZHIHU_COOKIE_EXPIRES_AT in .env (ISO time) to enable cookie expiry reminders.";
  }

  const expiresAt = new Date(expiresAtValue);
  if (Number.isNaN(expiresAt.getTime())) {
    return "ZHIHU_COOKIE_EXPIRES_AT is invalid. Use ISO format like 2026-07-01T01:00:00+08:00.";
  }

  const diffMs = expiresAt.getTime() - Date.now();
  const diffDays = diffMs / (24 * 60 * 60 * 1000);

  if (diffMs <= 0) {
    return "Zhihu cookie appears expired. Please refresh ZHIHU_COOKIE.";
  }

  if (diffDays <= 3) {
    return `Zhihu cookie expires soon (${diffDays.toFixed(1)} days left). Please refresh in advance.`;
  }

  return "";
}

function toErrorMessage(error) {
  if (!error) {
    return "Unknown error";
  }

  if (typeof error === "string") {
    return error;
  }

  return error.message || String(error);
}

function formatZhihuWebsiteUnavailable(error, hasCookie) {
  const message = toErrorMessage(error);

  if (
    /Request failed \(403\):\s*https?:\/\/www\.zhihu\.com\//i.test(message)
  ) {
    if (hasCookie) {
      return "Zhihu website unavailable: request blocked (403). Refresh ZHIHU_COOKIE and retry.";
    }

    return "Zhihu website unavailable: request blocked (403). Provide --zhihu-cookie or set ZHIHU_COOKIE in .env.";
  }

  if (
    /Request failed \(401\):\s*https?:\/\/www\.zhihu\.com\//i.test(message)
  ) {
    return "Zhihu API unauthorized (401). Add ZHIHU_COOKIE or use --zhihu-json-url fallback.";
  }

  return `Zhihu unavailable: ${message}`;
}

function hasFlag(flag) {
  return process.argv.includes(flag);
}

function getLocalDateKey(date) {
  const y = date.getFullYear();
  const m = String(date.getMonth() + 1).padStart(2, "0");
  const d = String(date.getDate()).padStart(2, "0");
  return `${y}-${m}-${d}`;
}

function hhmmNow(date) {
  const h = String(date.getHours()).padStart(2, "0");
  const m = String(date.getMinutes()).padStart(2, "0");
  return `${h}:${m}`;
}

function stripHtml(input) {
  return String(input || "")
    .replace(/<[^>]+>/g, " ")
    .replace(/&nbsp;/g, " ")
    .replace(/&amp;/g, "&")
    .replace(/&quot;/g, '"')
    .replace(/&#39;/g, "'")
    .replace(/\s+/g, " ")
    .trim();
}

function tryExtractHeat(text) {
  const heatMatch = String(text || "").match(/([0-9][0-9,\.]*)\s*(万)?\s*热度/i);
  if (heatMatch) {
    const base = Number.parseFloat(heatMatch[1].replace(/,/g, ""));
    if (Number.isFinite(base)) {
      return heatMatch[2] ? Math.round(base * 10000) : Math.round(base);
    }
  }

  const match = String(text || "").match(/([0-9][0-9,\.]*)\s*(赞同|点赞|votes?|upvotes?)/i);
  if (!match) {
    return 0;
  }

  const normalized = match[1].replace(/,/g, "");
  const value = Number.parseFloat(normalized);
  if (!Number.isFinite(value)) {
    return 0;
  }

  return Math.round(value);
}

async function fetchJsonWithTimeout(url, timeoutMs = 12000, init = {}) {
  const timeoutPromise = new Promise((_, reject) => {
    setTimeout(() => reject(new Error(`Request timeout after ${timeoutMs}ms: ${url}`)), timeoutMs);
  });

  const fetchPromise = (async () => {
    const response = await fetch(url, init);
    if (!response.ok) {
      throw new Error(`Request failed (${response.status}): ${url}`);
    }
    return response.json();
  })();

  return Promise.race([fetchPromise, timeoutPromise]);
}

async function fetchTextWithTimeout(url, timeoutMs = 12000, init = {}) {
  const timeoutPromise = new Promise((_, reject) => {
    setTimeout(() => reject(new Error(`Request timeout after ${timeoutMs}ms: ${url}`)), timeoutMs);
  });

  const fetchPromise = (async () => {
    const response = await fetch(url, init);
    if (!response.ok) {
      throw new Error(`Request failed (${response.status}): ${url}`);
    }
    return response.text();
  })();

  return Promise.race([fetchPromise, timeoutPromise]);
}

async function fetchZhihuTopAnswersFromApi(limit = 10, cookie = "") {
  const headers = {
    "User-Agent": "Mozilla/5.0"
  };
  if (cookie) {
    headers.Cookie = cookie;
  }

  const hotUrl = "https://www.zhihu.com/api/v3/feed/topstory/hot-lists/total?limit=50&desktop=true";
  const hotData = await fetchJsonWithTimeout(hotUrl, 15000, { headers });

  const questions = (hotData.data || [])
    .map((item) => ({
      id: item?.target?.id,
      title: item?.target?.title
    }))
    .filter((q) => q.id && q.title)
    .slice(0, limit);

  const answerResults = await Promise.all(
    questions.map(async (q) => {
      const answerUrl = `https://www.zhihu.com/api/v4/questions/${q.id}/answers?limit=1&offset=0&sort_by=voteups`;

      try {
        const answerData = await fetchJsonWithTimeout(answerUrl, 12000, { headers });
        const answer = answerData?.data?.[0];
        if (!answer) {
          return null;
        }

        const excerpt = String(answer.excerpt || "").replace(/\s+/g, " ").trim();
        return {
          source: "Zhihu",
          title: q.title,
          link: `https://www.zhihu.com/question/${q.id}/answer/${answer.id}`,
          score: Number(answer.voteup_count || 0),
          summary: excerpt,
          author: answer?.author?.name || "unknown"
        };
      } catch {
        return null;
      }
    })
  );

  return answerResults.filter(Boolean).sort((a, b) => b.score - a.score);
}

function parseGenericTopJsonItems(jsonData, sourceName) {
  const list =
    jsonData?.data ||
    jsonData?.result ||
    jsonData?.items ||
    jsonData?.list ||
    (Array.isArray(jsonData) ? jsonData : []);

  if (!Array.isArray(list)) {
    return [];
  }

  return list
    .map((item) => {
      const title = item?.title || item?.name || item?.question || item?.text;
      const link = item?.url || item?.link || item?.href;
      const summary = item?.summary || item?.desc || item?.description || "";
      const author = item?.author || item?.user || "unknown";
      const score = Number(item?.score || item?.voteup_count || item?.upvotes || 0);

      if (!title || !link) {
        return null;
      }

      return {
        source: sourceName,
        title: String(title),
        link: String(link),
        score: Number.isFinite(score) ? score : 0,
        summary: String(summary),
        author: String(author)
      };
    })
    .filter(Boolean);
}

async function fetchZhihuFromJsonUrl(jsonUrl, limit = 10) {
  const data = await fetchJsonWithTimeout(jsonUrl, 15000, {
    headers: {
      "User-Agent": "Mozilla/5.0"
    }
  });

  return parseGenericTopJsonItems(data, "Zhihu").slice(0, limit);
}

function parseZhihuHotValue(text) {
  const match = String(text || "").match(/([0-9][0-9.]*)\s*万?\s*热度/);
  if (!match) {
    return 0;
  }

  const base = Number.parseFloat(match[1]);
  if (!Number.isFinite(base)) {
    return 0;
  }

  return /万/.test(text) ? Math.round(base * 10000) : Math.round(base);
}

async function fetchZhihuFromPublicHotlist(publicUrl, limit = 10) {
  const data = await fetchJsonWithTimeout(publicUrl, 15000, {
    headers: {
      "User-Agent": "Mozilla/5.0"
    }
  });

  const list = Array.isArray(data?.data) ? data.data : [];
  return list
    .filter((item) => item?.title && item?.link)
    .slice(0, limit)
    .map((item) => ({
      source: "Zhihu",
      title: String(item.title),
      link: String(item.link),
      score: parseZhihuHotValue(item.hot_value_desc),
      summary: String(item.detail || "").replace(/\s+/g, " ").trim(),
      author: "unknown"
    }));
}

function parseZhihuHotFromHtml(htmlText, pageUrl) {
  const results = [];
  const answerLinkRegex = /<a[^>]+href="(\/question\/\d+\/answer\/\d+[^"#]*)"[^>]*>([\s\S]*?)<\/a>/gi;

  let match;
  while ((match = answerLinkRegex.exec(htmlText))) {
    const href = match[1];
    const inner = match[2];
    const title = stripHtml(inner);
    if (!title || title.length < 8) {
      continue;
    }

    const nearbyStart = Math.max(0, match.index - 220);
    const nearbyEnd = Math.min(htmlText.length, match.index + 420);
    const nearbyText = stripHtml(htmlText.slice(nearbyStart, nearbyEnd));
    const score = tryExtractHeat(nearbyText);

    results.push({
      source: "Zhihu",
      title,
      link: new URL(href, "https://www.zhihu.com").toString(),
      score,
      summary: "",
      author: "unknown",
      from: pageUrl
    });
  }

  const dedup = new Map();
  for (const item of results) {
    if (!dedup.has(item.link)) {
      dedup.set(item.link, item);
    }
  }

  return [...dedup.values()];
}

async function fetchZhihuTopFromWebsite({ hotUrls, cookie, perPage = 10 }) {
  const urls = hotUrls.filter(Boolean);
  if (urls.length === 0) {
    return [];
  }

  const all = [];
  for (const url of urls) {
    const headers = {
      "User-Agent": "Mozilla/5.0",
      Accept: "text/html,application/xhtml+xml"
    };
    if (cookie) {
      headers.Cookie = cookie;
    }

    const html = await fetchTextWithTimeout(url, 15000, { headers });
    const pageItems = parseZhihuHotFromHtml(html, url).slice(0, perPage);
    all.push(...pageItems);
  }

  const dedup = new Map();
  for (const item of all) {
    if (!dedup.has(item.link)) {
      dedup.set(item.link, item);
    }
  }

  return [...dedup.values()].sort((a, b) => b.score - a.score);
}
function buildDigestText({ zhihuItems, errors = [], topN = 8 }) {
  const mixed = [...zhihuItems]
    .sort((a, b) => b.score - a.score)
    .slice(0, topN);

  const lines = [
    `[Daily Insight Digest] ${new Date().toLocaleString()}`,
    "",
    `Zhihu candidates: ${zhihuItems.length}`,
    "Top picks:"
  ];

  if (errors.length > 0) {
    lines.push("");
    lines.push("Source status:");
    errors.forEach((e) => lines.push(`- ${e}`));
    lines.push("");
  }

  mixed.forEach((item, idx) => {
    lines.push(`${idx + 1}. [${item.source}] ${item.title}`);
    lines.push(`   score: ${item.score} | author: ${item.author}`);
    if (item.summary) {
      lines.push(`   summary: ${item.summary.slice(0, 160)}`);
    }
    lines.push(`   link: ${item.link}`);
  });

  return lines.join("\n");
}

async function runDailyDigestOnce({
  webhook,
  zhihuHotUrls,
  zhihuCookie,
  zhihuJsonUrl,
  zhihuLimit
}) {
  const errors = [];
  const hasCookie = Boolean(zhihuCookie && zhihuCookie.trim());

  let zhihuItems = [];
  // Primary source: public hot-list mirror that needs no cookie/login.
  try {
    zhihuItems = await fetchZhihuFromPublicHotlist(ZHIHU_PUBLIC_HOTLIST_URL, zhihuLimit);
  } catch (publicError) {
    errors.push(`Zhihu public hotlist unavailable: ${publicError.message || publicError}`);
  }

  try {
    let apiUnauthorized = false;
    if (zhihuItems.length === 0) {
      try {
        zhihuItems = await fetchZhihuTopAnswersFromApi(zhihuLimit, zhihuCookie);
      } catch (apiError) {
        const apiMessage = formatZhihuWebsiteUnavailable(apiError, hasCookie);
        errors.push(apiMessage);
        if (/unauthorized \(401\)/i.test(apiMessage)) {
          apiUnauthorized = true;
        }
      }
    }

    // If API already returned 401 and no cookie exists, website fetch is very likely blocked too.
    const shouldTryWebsite = !(apiUnauthorized && !hasCookie);

    if (zhihuItems.length === 0 && shouldTryWebsite) {
      try {
        zhihuItems = await fetchZhihuTopFromWebsite({
          hotUrls: zhihuHotUrls,
          cookie: zhihuCookie,
          perPage: zhihuLimit
        });
      } catch (websiteError) {
        errors.push(formatZhihuWebsiteUnavailable(websiteError, Boolean(zhihuCookie)));
      }
    }

    if (zhihuItems.length === 0 && zhihuJsonUrl) {
      zhihuItems = await fetchZhihuFromJsonUrl(zhihuJsonUrl, zhihuLimit);
    }
  } catch (error) {
    errors.push(`Zhihu unavailable: ${error.message || error}`);
  }

  const digestText = buildDigestText({ zhihuItems, errors, topN: 8 });

  await pushToFeishu({
    webhook,
    name: "daily-insight-digest",
    description: "Zhihu top answers",
    filePath: "daily-digest",
    preview: digestText
  });

  return {
    zhihuCount: zhihuItems.length,
    errors,
    digestText
  };
}

async function startDailyScheduler({
  webhook,
  time,
  zhihuHotUrls,
  zhihuCookie,
  zhihuJsonUrl,
  zhihuLimit,
  runNow
}) {
  let isRunning = false;
  let lastRunDay = "";

  const tick = async () => {
    const now = new Date();
    const today = getLocalDateKey(now);
    const current = hhmmNow(now);
    const shouldRun = current === time && lastRunDay !== today;

    if (!shouldRun || isRunning) {
      return;
    }

    isRunning = true;
    try {
      const result = await runDailyDigestOnce({
        webhook,
        zhihuHotUrls,
        zhihuCookie,
        zhihuJsonUrl,
        zhihuLimit
      });

      lastRunDay = today;
      console.log(
        `Digest pushed at ${new Date().toLocaleString()} | Zhihu=${result.zhihuCount}`
      );
    } catch (error) {
      console.error(`Scheduled digest failed: ${error.message || error}`);
    } finally {
      isRunning = false;
    }
  };

  if (runNow) {
    try {
      const result = await runDailyDigestOnce({
        webhook,
        zhihuHotUrls,
        zhihuCookie,
        zhihuJsonUrl,
        zhihuLimit
      });
      console.log(
        `Immediate digest pushed | Zhihu=${result.zhihuCount}`
      );
    } catch (error) {
      console.error(`Immediate digest failed: ${error.message || error}`);
    }
  }

  console.log(`Daily scheduler started. Next run at ${time} local time.`);
  setInterval(() => {
    tick().catch((error) => {
      console.error(`Scheduler tick failed: ${error.message || error}`);
    });
  }, 30_000);
}

function toSlug(input) {
  return input
    .toLowerCase()
    .replace(/[^a-z0-9-\s]/g, "")
    .trim()
    .replace(/\s+/g, "-")
    .replace(/-+/g, "-");
}

async function generateSkillWithMcp({ name, description }) {
  const transport = new StdioClientTransport({
    command: process.execPath,
    args: ["src/mcp-server.js"]
  });

  const client = new Client(
    {
      name: "skill-demo-cli",
      version: "1.0.0"
    },
    {
      capabilities: {}
    }
  );

  await client.connect(transport);

  try {
    const result = await client.callTool({
      name: "skill_scaffold",
      arguments: {
        name,
        description
      }
    });

    const markdown =
      result.content?.find((item) => item.type === "text")?.text || "";

    if (!markdown) {
      throw new Error("MCP tool returned empty content.");
    }

    return markdown;
  } finally {
    await transport.close();
  }
}

async function saveSkillFile(skillName, content) {
  const slug = toSlug(skillName) || "demo-skill";
  const dir = path.join(SKILLS_DIR, slug);
  const filePath = path.join(dir, "SKILL.md");

  await mkdir(dir, { recursive: true });
  await writeFile(filePath, content, "utf8");

  return filePath;
}

function getPythonExecutorTemplate(skillName) {
  return [
    "import json",
    "import sys",
    "from typing import Any, Dict",
    "",
    "",
    "def run(payload: Dict[str, Any]) -> Dict[str, Any]:",
    "    user_query = str(payload.get(\"user_query\", \"\")).strip()",
    "    context = str(payload.get(\"context\", \"\")).strip()",
    "",
    "    actions = [",
    "        \"Parse user intent\",",
    "        \"Decide action path\",",
    "        \"Return concise response\",",
    "    ]",
    "",
    "    response = {",
    `        \"skill\": \"${skillName}\",`,
    "        \"intent\": \"Handle user request with workflow\",",
    "        \"actions\": actions,",
    "        \"response\": f\"Processed query: {user_query}\",",
    "        \"context_used\": bool(context),",
    "    }",
    "    return response",
    "",
    "",
    "def main() -> None:",
    "    raw = sys.argv[1] if len(sys.argv) > 1 else \"{}\"",
    "    payload = json.loads(raw)",
    "    result = run(payload)",
    "    print(json.dumps(result, ensure_ascii=False))",
    "",
    "",
    "if __name__ == \"__main__\":",
    "    main()",
    ""
  ].join("\n");
}

async function savePythonExecutorIfMissing(skillName) {
  const slug = toSlug(skillName) || "demo-skill";
  const dir = path.join(SKILLS_DIR, slug);
  const filePath = path.join(dir, "main.py");

  await mkdir(dir, { recursive: true });

  try {
    await access(filePath);
    return { filePath, created: false };
  } catch {
    const content = getPythonExecutorTemplate(skillName);
    await writeFile(filePath, content, "utf8");
    return { filePath, created: true };
  }
}

async function listSkills() {
  try {
    const folders = await readdir(SKILLS_DIR, { withFileTypes: true });
    const skillFolders = folders.filter((entry) => entry.isDirectory()).map((entry) => entry.name);

    if (skillFolders.length === 0) {
      console.log("No skills found.");
      return;
    }

    console.log("Skills:");
    for (const folder of skillFolders) {
      console.log(`- ${folder}`);
    }
  } catch (error) {
    if (error && error.code === "ENOENT") {
      console.log("No skills found.");
      return;
    }

    throw error;
  }
}

async function readSkillFileByName(skillName) {
  const slug = toSlug(skillName);
  if (!slug) {
    throw new Error("--name is required for push command.");
  }

  const filePath = path.join(SKILLS_DIR, slug, "SKILL.md");
  const content = await readFile(filePath, "utf8");
  return { filePath, content };
}

async function runPythonExecutor({ skillName, pythonCommand, userQuery, context }) {
  const slug = toSlug(skillName);
  if (!slug) {
    throw new Error("--name is required for exec command.");
  }

  const executorPath = path.join(SKILLS_DIR, slug, "main.py");
  const payload = JSON.stringify({
    user_query: userQuery,
    context
  });

  const { stdout, stderr } = await execFile(pythonCommand, [executorPath, payload], {
    cwd: process.cwd()
  });

  if (stderr && stderr.trim()) {
    throw new Error(`Python executor stderr: ${stderr.trim()}`);
  }

  const output = stdout.trim();
  if (!output) {
    throw new Error("Python executor returned empty output.");
  }

  return output;
}

async function pushToFeishu({ webhook, name, description, filePath, preview }) {
  const text = [
    "[Skill Demo]",
    `name: ${name}`,
    `description: ${description}`,
    `file: ${filePath}`,
    "preview:",
    preview
  ].join("\n");

  const resp = await fetch(webhook, {
    method: "POST",
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify({
      msg_type: "text",
      content: {
        text
      }
    })
  });

  if (!resp.ok) {
    const body = await resp.text();
    throw new Error(`Feishu push failed (${resp.status}): ${body}`);
  }
}

async function main() {
  await loadDotEnvFile();

  const command = process.argv[2] || "create";
  const name = getArg("--name", "demo-skill");
  const description = getArg(
    "--description",
    "A demo skill generated via MCP and CLI."
  );
  const webhook =
    getArg("--webhook") ||
    process.env.FEISHU_WEBHOOK_URL ||
    DEFAULT_FEISHU_WEBHOOK;

  if (command === "daily") {
    const time = getArg("--time", "01:00");
    const zhihuHotRaw =
      getArg("--zhihu-hot-urls") ||
      process.env.ZHIHU_HOT_URLS ||
      "https://www.zhihu.com/hot";
    const zhihuHotUrls = zhihuHotRaw
      .split(",")
      .map((item) => item.trim())
      .filter(Boolean);
    const zhihuCookie = getArg("--zhihu-cookie", process.env.ZHIHU_COOKIE || "");
    const zhihuCookieExpiresAt = getArg(
      "--zhihu-cookie-expires-at",
      process.env.ZHIHU_COOKIE_EXPIRES_AT || ""
    );
    const zhihuJsonUrl = getArg("--zhihu-json-url", process.env.ZHIHU_JSON_URL || "");
    const zhihuLimit = Number.parseInt(getArg("--zhihu-limit", "10"), 10);

    if (!/^([01]\d|2[0-3]):[0-5]\d$/.test(time)) {
      throw new Error("--time must be in HH:MM format, for example 01:00");
    }

    const warning = cookieSafetyWarning(zhihuCookie, zhihuCookieExpiresAt);
    if (warning) {
      console.warn(`[daily] ${warning}`);
    }

    if (hasFlag("--once")) {
      const result = await runDailyDigestOnce({
        webhook,
        zhihuHotUrls,
        zhihuCookie,
        zhihuJsonUrl,
        zhihuLimit: Number.isFinite(zhihuLimit) ? zhihuLimit : 10
      });
      if (result.errors.length > 0) {
        console.log("Source status:");
        result.errors.forEach((item) => console.log(`- ${item}`));
      }
      console.log(
        `Daily digest pushed once | Zhihu=${result.zhihuCount}, Errors=${result.errors.length}`
      );
      return;
    }

    await startDailyScheduler({
      webhook,
      time,
      zhihuHotUrls,
      zhihuCookie,
      zhihuJsonUrl,
      zhihuLimit: Number.isFinite(zhihuLimit) ? zhihuLimit : 10,
      runNow: hasFlag("--run-now")
    });

    return;
  }

  if (command === "list") {
    await listSkills();
    return;
  }

  if (command === "create") {
    console.log("1/3 Calling MCP tool to generate skill template...");
    const markdown = await generateSkillWithMcp({ name, description });

    console.log("2/3 Saving generated SKILL.md to local workspace...");
    const filePath = await saveSkillFile(name, markdown);

    const pyResult = await savePythonExecutorIfMissing(name);

    const shouldPush = process.argv.includes("--push");
    if (shouldPush) {
      console.log("3/3 Pushing summary to Feishu bot...");
      const preview = markdown.split("\n").slice(0, 10).join("\n");
      await pushToFeishu({ webhook, name, description, filePath, preview });
    } else {
      console.log("3/3 Skipped Feishu push (add --push to enable).");
    }

    console.log("Done.");
    console.log(`Generated file: ${filePath}`);
    console.log(
      `${pyResult.created ? "Created" : "Reused"} python executor: ${pyResult.filePath}`
    );
    return;
  }

  if (command === "exec") {
    const pythonCommand = getArg("--python", process.env.PYTHON_BIN || "python");
    const userQuery = getArg("--query", "Help me with my request.");
    const context = getArg("--context", "");

    const output = await runPythonExecutor({
      skillName: name,
      pythonCommand,
      userQuery,
      context
    });

    console.log("Executor output:");
    console.log(output);

    if (process.argv.includes("--push")) {
      await pushToFeishu({
        webhook,
        name,
        description: "Python executor output",
        filePath: path.join(SKILLS_DIR, toSlug(name), "main.py"),
        preview: output.slice(0, 500)
      });
      console.log("Feishu push sent for exec output.");
    }

    return;
  }

  if (command === "push") {
    const { filePath, content } = await readSkillFileByName(name);
    const preview = content.split("\n").slice(0, 10).join("\n");

    await pushToFeishu({
      webhook,
      name,
      description: getArg("--description", "Push existing skill to Feishu."),
      filePath,
      preview
    });

    console.log("Done.");
    console.log(`Pushed to Feishu: ${filePath}`);
    return;
  }

  throw new Error(
    `Unknown command: ${command}. Use one of: create, list, push, exec, daily.`
  );
}

main().catch((error) => {
  console.error(error.message || error);
  process.exit(1);
});
