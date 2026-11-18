"""Build the 2-shot chat messages for one task.

The instruction text is the paper's zero-shot prompt, unchanged. Each example is a
user turn (instruction + problem) followed by an assistant turn (the human solution
in a ```cpp block, so the notebook's extraction regex still applies). The real task
comes last.

    from build_prompt import build_messages
    messages = build_messages(description)   # pass as "messages" to OpenRouter
"""
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))

INSTRUCTION = (
    "You are a competitive programming assistant.\n"
    "                Write a complete, efficient C++ program using standard input/output to solve this problem \n"
    "                Please do not include explanation. Only Code:\n\n"
    "                {description}\n"
    "            "
)

with open(os.path.join(HERE, "shots.json"), encoding="utf-8") as f:
    SHOTS = json.load(f)


def build_messages(description):
    messages = []
    for shot in SHOTS:
        messages.append({"role": "user", "content": INSTRUCTION.format(description=shot["description"])})
        messages.append({"role": "assistant", "content": f"```cpp\n{shot['code']}\n```"})
    messages.append({"role": "user", "content": INSTRUCTION.format(description=description)})
    return messages
