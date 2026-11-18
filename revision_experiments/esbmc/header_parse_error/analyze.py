"""
analyze.py
==========
Summarises the header-fix run (summary.csv) against the e2 run.

Writes:
  verdicts_by_model.csv      verdict counts per model after the header fix
  residual_parse_errors.csv  first clang error per file that still fails to parse
  e2_with_header_fix.csv     e2 verdict counts per model, with the header-fix
                             verdicts substituted for the files in this set

Run from the repository root:

    python3.11 revision_experiments/esbmc/header_parse_error/analyze.py
"""

import collections
import csv
import json
import os
import re
import subprocess

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
E2 = os.path.join(REPO, "revision_experiments", "esbmc", "runs",
                  "e2_overflow_u10_t60", "summary.csv")
VERDICTS = ["SUCCESS", "FAILED", "TIMEOUT", "PARSE_ERROR", "ERROR"]
MODELS = ["gemma", "llama", "qwen", "human"]
ERR_RE = re.compile(r"error: (.*)")
ESBMC_BIN = os.path.join(REPO, "esbmc", "bin", "esbmc")


def table(rows, key="model"):
    c = collections.defaultdict(collections.Counter)
    for r in rows:
        c[r[key]][r["verdict"]] += 1
    out = []
    for m in MODELS + ["all"]:
        cnt = sum(c.values(), collections.Counter()) if m == "all" else c[m]
        n = sum(cnt.values())
        if not n:
            continue
        row = {"model": m, "n": n, **{v: cnt[v] for v in VERDICTS}}
        row["analyzable_pct"] = round(100 * (cnt["SUCCESS"] + cnt["FAILED"]) / n, 1)
        out.append(row)
    return out


def write(path, rows):
    with open(path, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)


def first_error(sid):
    with open(os.path.join(HERE, "json", sid + ".json")) as f:
        d = json.load(f)
    text = d.get("stderr_head", "") + "\n" + d.get("stdout_head", "")
    m = ERR_RE.search(text)
    if m:
        return m.group(1).strip()
    # stderr_head keeps only 500 chars; re-parse to get the full message
    proc = subprocess.run([ESBMC_BIN, "--parse-tree-only",
                           os.path.join(HERE, "cpp", sid)],
                          stdout=subprocess.PIPE, stderr=subprocess.STDOUT,
                          timeout=120)
    m = ERR_RE.search(proc.stdout.decode("utf-8", errors="replace"))
    return m.group(1).strip() if m else ""


def main():
    fixed = list(csv.DictReader(open(os.path.join(HERE, "summary.csv"))))
    by_model = table(fixed)
    write(os.path.join(HERE, "verdicts_by_model.csv"), by_model)

    manifest = {r["sample_id"]: r for r in csv.DictReader(open(os.path.join(HERE, "manifest.csv")))}
    residual = []
    for r in fixed:
        if r["verdict"] != "PARSE_ERROR":
            continue
        residual.append({"sample_id": r["sample_id"], "model": r["model"],
                         "other_includes": manifest[r["sample_id"]]["other_includes"],
                         "first_error": first_error(r["sample_id"])})
    if residual:
        write(os.path.join(HERE, "residual_parse_errors.csv"), residual)

    fixed_v = {r["sample_id"]: r["verdict"] for r in fixed}
    e2 = list(csv.DictReader(open(E2)))
    merged = [{**r, "verdict": fixed_v.get(r["sample_id"], r["verdict"])} for r in e2]
    before, after = table(e2), table(merged)
    combo = []
    for b, a in zip(before, after):
        combo.append({"model": b["model"], "n": b["n"],
                      **{f"{v}_e2": b[v] for v in VERDICTS},
                      **{f"{v}_fixed": a[v] for v in VERDICTS},
                      "analyzable_pct_e2": b["analyzable_pct"],
                      "analyzable_pct_fixed": a["analyzable_pct"]})
    write(os.path.join(HERE, "e2_with_header_fix.csv"), combo)

    print("Header-fix set, verdicts by model:")
    for r in by_model:
        print("  ", r)
    print("\nWhole benchmark, e2 vs e2 with header fix:")
    for r in combo:
        print("  ", r)
    print(f"\nResidual parse errors: {len(residual)}; most common first errors:")
    for msg, n in collections.Counter(
            re.sub(r"'[^']*'", "'X'", r["first_error"]) for r in residual).most_common(15):
        print(f"  {n:5d}  {msg}")


if __name__ == "__main__":
    main()
