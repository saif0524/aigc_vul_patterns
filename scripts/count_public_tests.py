# scripts/count_public_tests.py
# Usage:
#   python3.11 scripts/count_public_tests.py data/testcases/testcases-train-00000.json data/testcases/testcases-train-00001.json data/testcases/testcases-train-00002.json
# or:
#   python3.11 scripts/count_public_tests.py data/testcases/testcases-train-*.json

import json
import sys
from pathlib import Path

def has_public_tests(p: dict) -> bool:
    pub = p.get("public_tests") or {}
    ins = pub.get("input") or []
    outs = pub.get("output") or []
    return len(ins) > 0 and len(outs) > 0 and len(ins) == len(outs)

def main(paths):
    total_all = 0
    with_pub_all = 0
    empty_pub_all = 0
    bad_pub_all = 0

    for fp in paths:
        data = json.load(open(fp, "r", encoding="utf-8"))

        total = len(data)
        with_pub = 0
        empty_pub = 0
        bad_pub = 0

        for p in data:
            pub = p.get("public_tests") or {}
            ins = pub.get("input") or []
            outs = pub.get("output") or []

            if len(ins) == 0 and len(outs) == 0:
                empty_pub += 1
            elif has_public_tests(p):
                with_pub += 1
            else:
                # e.g., inputs exist but outputs missing, or length mismatch
                bad_pub += 1

        total_all += total
        with_pub_all += with_pub
        empty_pub_all += empty_pub
        bad_pub_all += bad_pub

        print(f"{fp}: total={total} with_public_tests={with_pub} empty_public_tests={empty_pub} malformed_public_tests={bad_pub}")

    print("-" * 72)
    print(f"ALL: total={total_all} with_public_tests={with_pub_all} empty_public_tests={empty_pub_all} malformed_public_tests={bad_pub_all}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3.11 scripts/count_public_tests.py <testcases.json> [more.json ...]")
        sys.exit(1)

    # allow globs expanded by shell
    paths = [str(Path(p)) for p in sys.argv[1:]]
    main(paths)
