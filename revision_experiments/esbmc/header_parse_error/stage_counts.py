"""
stage_counts.py
===============
ESBMC verdicts for the whole benchmark (8,918 programs) at each stage:

  0_e2            reported run (e2_overflow_u10_t60), unmodified sources
  1_header        + <bits/stdc++.h> replaced by ESBMC-compatible headers
  2_header_fastio + fast-I/O calls (sync_with_stdio, cin.tie) disabled
  3_header_fastio_braces
                  + braces added around brace-less range-for bodies
                    (only for programs where ESBMC crashed at stage 2)

A program keeps its verdict from the previous stage unless it was rerun at
this stage. Verdicts are read from the per-file JSONs, so the script also
works while a run is in progress (the "files_done" column shows how far).

Writes, next to this script:
  stage_counts.csv    one row per stage x model (plus "AI" and "all")
  stage_verdicts.csv  one row per program, its verdict at each stage

Run from anywhere:

    python3.11 revision_experiments/esbmc/header_parse_error/stage_counts.py
"""

import collections
import csv
import glob
import json
import os

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
E2 = os.path.join(REPO, "revision_experiments", "esbmc", "runs",
                  "e2_overflow_u10_t60", "summary.csv")
STAGES = [("1_header", HERE),
          ("2_header_fastio", os.path.join(HERE, "fastio_removed")),
          ("3_header_fastio_braces", os.path.join(HERE, "rangefor_braces"))]
VERDICTS = ["SUCCESS", "FAILED", "TIMEOUT", "PARSE_ERROR", "ERROR"]
GROUPS = ["gemma", "llama", "qwen", "human", "AI", "all"]


def load_stage(run_dir):
    """sample_id -> verdict from json/, plus the number of files planned."""
    out = {}
    root = os.path.join(run_dir, "json")
    for p in glob.glob(os.path.join(root, "**", "*.cpp.json"), recursive=True):
        with open(p) as f:
            out[os.path.relpath(p, root)[: -len(".json")]] = json.load(f)["verdict"]
    manifest = os.path.join(run_dir, "manifest.csv")
    planned = sum(1 for _ in csv.DictReader(open(manifest))) if os.path.exists(manifest) else 0
    return out, planned


def main():
    rows = list(csv.DictReader(open(E2)))
    per_sample = {r["sample_id"]: {"model": r["model"], "0_e2": r["verdict"]} for r in rows}
    progress = {"0_e2": (len(rows), len(rows))}

    prev = "0_e2"
    for name, run_dir in STAGES:
        verdicts, planned = load_stage(run_dir)
        progress[name] = (len(verdicts), planned)
        for sid, rec in per_sample.items():
            rec[name] = verdicts.get(sid, rec[prev])
        prev = name
    stage_names = ["0_e2"] + [s for s, _ in STAGES]

    with open(os.path.join(HERE, "stage_verdicts.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["sample_id", "model"] + stage_names)
        for sid in sorted(per_sample):
            rec = per_sample[sid]
            w.writerow([sid, rec["model"]] + [rec[s] for s in stage_names])

    table = []
    for stage in stage_names:
        counts = collections.defaultdict(collections.Counter)
        for rec in per_sample.values():
            v = rec[stage]
            counts[rec["model"]][v] += 1
            counts["all"][v] += 1
            if rec["model"] != "human":
                counts["AI"][v] += 1
        done, planned = progress[stage]
        for g in GROUPS:
            c = counts[g]
            n = sum(c.values())
            conclusive = c["SUCCESS"] + c["FAILED"]
            table.append({
                "stage": stage, "group": g, "n": n,
                **{v: c[v] for v in VERDICTS},
                "parse_error_pct": round(100 * c["PARSE_ERROR"] / n, 1),
                "conclusive": conclusive,
                "conclusive_pct": round(100 * conclusive / n, 1),
                "failed_rate_among_conclusive_pct":
                    round(100 * c["FAILED"] / conclusive, 1) if conclusive else "",
                "files_done": f"{done}/{planned}",
            })

    with open(os.path.join(HERE, "stage_counts.csv"), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(table[0].keys()))
        w.writeheader()
        w.writerows(table)

    hdr = f"{'stage':16} {'group':6} {'n':>5} " + " ".join(f"{v[:7]:>7}" for v in VERDICTS) \
        + f" {'PE%':>5} {'concl%':>6} {'fail%':>6}  done"
    print(hdr)
    for r in table:
        print(f"{r['stage']:16} {r['group']:6} {r['n']:>5} "
              + " ".join(f"{r[v]:>7}" for v in VERDICTS)
              + f" {r['parse_error_pct']:>5} {r['conclusive_pct']:>6} "
              f"{r['failed_rate_among_conclusive_pct']:>6}  {r['files_done']}")


if __name__ == "__main__":
    main()
