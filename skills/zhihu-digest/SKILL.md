# zhihu-digest

## Purpose
Fetch top Zhihu hot answers daily and push a digest to Feishu

## Capabilities
- Identify the user intent from natural language input
- Select a matching action path
- Return concise and actionable response

## Constraints
- Ask for clarification when required fields are missing
- Do not fabricate unavailable data
- Keep final response under 200 words unless user asks for detail

## Inputs
- user_query: Raw user request
- context: Optional background information

## Outputs
- intent: one-line intent summary
- actions: action list
- response: final text for user

## Tooling
- primary_tool: internal-workflow
- fallback_tool: none

## Workflow
1. Parse request and extract key entities
2. Validate required information
3. Build action plan
4. Produce concise response

## Example
Input: "总结知乎今天的 AI 热门问答"
Output:
- intent: Summarize high-signal Zhihu answers
- actions:
  1) Collect candidate answers
  2) Rank by voteup/heat signal
  3) Generate concise digest
- response: Here are today's top Zhihu answers with links and key takeaways.

## Metadata
- generated_by: skill_scaffold
- version: 1.0.0
- executor: python
- entrypoint: skills/zhihu-digest/main.py
- function: run