import { Server } from "@modelcontextprotocol/sdk/server/index.js";
import { StdioServerTransport } from "@modelcontextprotocol/sdk/server/stdio.js";
import {
  CallToolRequestSchema,
  ListToolsRequestSchema
} from "@modelcontextprotocol/sdk/types.js";

const server = new Server(
  {
    name: "skill-demo-server",
    version: "1.0.0"
  },
  {
    capabilities: {
      tools: {}
    }
  }
);

function toSlug(input) {
  return input
    .toLowerCase()
    .replace(/[^a-z0-9-\s]/g, "")
    .trim()
    .replace(/\s+/g, "-")
    .replace(/-+/g, "-");
}

server.setRequestHandler(ListToolsRequestSchema, async () => {
  return {
    tools: [
      {
        name: "skill_scaffold",
        description: "Generate a practical SKILL.md template with constraints and examples.",
        inputSchema: {
          type: "object",
          properties: {
            name: {
              type: "string",
              description: "Skill name, used for title and folder naming."
            },
            description: {
              type: "string",
              description: "Short description for the skill."
            }
          },
          required: ["name", "description"]
        }
      }
    ]
  };
});

server.setRequestHandler(CallToolRequestSchema, async (request) => {
  const { name, arguments: args } = request.params;

  if (name !== "skill_scaffold") {
    return {
      isError: true,
      content: [{ type: "text", text: `Unknown tool: ${name}` }]
    };
  }

  const skillName = String(args?.name || "demo-skill").trim();
  const skillDescription = String(args?.description || "No description").trim();
  const slug = toSlug(skillName) || "demo-skill";

  const skillMarkdown = [
    `# ${skillName}`,
    "",
    "## Purpose",
    skillDescription,
    "",
    "## Capabilities",
    "- Identify the user intent from natural language input",
    "- Select a matching action path",
    "- Return concise and actionable response",
    "",
    "## Constraints",
    "- Ask for clarification when required fields are missing",
    "- Do not fabricate unavailable data",
    "- Keep final response under 200 words unless user asks for detail",
    "",
    "## Inputs",
    "- user_query: Raw user request",
    "- context: Optional background information",
    "",
    "## Outputs",
    "- intent: one-line intent summary",
    "- actions: action list",
    "- response: final text for user",
    "",
    "## Tooling",
    "- primary_tool: internal-workflow",
    "- fallback_tool: none",
    "",
    "## Workflow",
    "1. Parse request and extract key entities",
    "2. Validate required information",
    "3. Build action plan",
    "4. Produce concise response",
    "",
    "## Example",
    "Input: \"总结知乎今天的 AI 热门问答\"",
    "Output:",
    "- intent: Summarize high-signal Zhihu answers",
    "- actions:",
    "  1) Collect candidate answers",
    "  2) Rank by voteup/heat signal",
    "  3) Generate concise digest",
    "- response: Here are today's top Zhihu answers with links and key takeaways.",
    "",
    "## Metadata",
    "- generated_by: skill_scaffold",
    "- version: 1.0.0",
    "- executor: python",
    `- entrypoint: skills/${slug}/main.py`,
    "- function: run"
  ].join("\n");

  return {
    content: [
      {
        type: "text",
        text: skillMarkdown
      }
    ]
  };
});

async function main() {
  const transport = new StdioServerTransport();
  await server.connect(transport);
}

main().catch((error) => {
  console.error("MCP server failed:", error);
  process.exit(1);
});
