import json
import sys
from typing import Any, Dict


def run(payload: Dict[str, Any]) -> Dict[str, Any]:
    user_query = str(payload.get("user_query", "")).strip()
    context = str(payload.get("context", "")).strip()

    actions = [
        "Parse user intent",
        "Decide action path",
        "Return concise response",
    ]

    response = {
        "skill": "zhihu-digest",
        "intent": "Handle user request with workflow",
        "actions": actions,
        "response": f"Processed query: {user_query}",
        "context_used": bool(context),
    }
    return response


def main() -> None:
    raw = sys.argv[1] if len(sys.argv) > 1 else "{}"
    payload = json.loads(raw)
    result = run(payload)
    print(json.dumps(result, ensure_ascii=False))


if __name__ == "__main__":
    main()
