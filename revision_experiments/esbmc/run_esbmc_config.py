"""
run_esbmc_config.py
===================
Run ESBMC on the benchmark under one fixed configuration and write everything
to revision_experiments/esbmc/runs/<run_name>/.

Reuses the task builder and the single-file runner from scripts/run_esbmc.py,
so the ESBMC command line is the same as in the replication package. Adds:
  - a configurable output root (outside analysis/)
  - per-file wall-clock runtime (the original runner leaves it at 0)
  - a meta.json with the config, machine load and timestamps
  - resume (skips files that already have a JSON) and an optional id list

Run from the repository root:

    python3.11 revision_experiments/esbmc/run_esbmc_config.py \
        --run-name e1_baseline_u10_t60 --no-overflow-check --jobs 8
"""

import argparse
import csv
import json
import os
import subprocess
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(REPO, "scripts"))
import run_esbmc as R  # noqa: E402

RUNS_DIR = os.path.join(REPO, "revision_experiments", "esbmc", "runs")


def run_timed(task):
    """run_esbmc_one plus wall-clock runtime stored in the output JSON."""
    t0 = time.monotonic()
    label, verdict, cwes = R.run_esbmc_one(task)
    elapsed = time.monotonic() - t0
    path = task["out_json_path"]
    with open(path) as f:
        data = json.load(f)
    data["runtime_seconds"] = round(elapsed, 2)
    with open(path, "w") as f:
        json.dump(data, f, indent=2)
    return label, verdict, cwes


def esbmc_version():
    out = subprocess.run([R.ESBMC_BIN, "--version"], stdout=subprocess.PIPE,
                         stderr=subprocess.STDOUT).stdout.decode().strip()
    return out.splitlines()[0] if out else "unknown"


def write_summary(out_root, summary_path):
    rows = []
    for dirpath, _, files in os.walk(out_root):
        for fn in files:
            if not fn.endswith(".cpp.json"):
                continue
            full = os.path.join(dirpath, fn)
            rel = os.path.relpath(full, out_root)[: -len(".json")]
            with open(full) as f:
                d = json.load(f)
            parts = rel.split("/")
            rows.append({
                "sample_id": rel,
                "model": parts[0],
                "generation": parts[1],
                "verdict": d["verdict"],
                "cwes": "|".join(d["cwes"]),
                "runtime_seconds": d.get("runtime_seconds", 0),
            })
    rows.sort(key=lambda r: r["sample_id"])
    with open(summary_path, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
        w.writeheader()
        w.writerows(rows)
    return rows


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--run-name", required=True)
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--unwind", type=int, default=R.DEFAULT_UNWIND)
    ap.add_argument("--timeout", type=int, default=R.DEFAULT_TIMEOUT)
    ap.add_argument("--no-overflow-check", dest="overflow_check",
                    action="store_false")
    ap.add_argument("--ids-file", help="text file, one sample_id per line")
    ap.add_argument("--no-resume", action="store_true")
    args = ap.parse_args()

    os.chdir(REPO)
    run_dir = os.path.join(RUNS_DIR, args.run_name)
    out_root = os.path.join(run_dir, "json")
    os.makedirs(out_root, exist_ok=True)

    cfg = {"timeout": args.timeout, "unwind": args.unwind,
           "overflow_check": args.overflow_check}
    paths = {"CPP_ROOT": "derived/cpp", "ANALYSIS_ROOT": out_root}
    tasks = R.build_llm_tasks(paths, cfg) + R.build_human_tasks(paths, cfg)

    if args.ids_file:
        with open(args.ids_file) as f:
            wanted = {line.strip() for line in f if line.strip()}
        tasks = [t for t in tasks if t["label"] in wanted]
    if not args.no_resume:
        tasks = [t for t in tasks if not os.path.exists(t["out_json_path"])]

    meta_path = os.path.join(run_dir, "meta.json")
    meta = {
        "run_name": args.run_name,
        "esbmc": esbmc_version(),
        "flags": {"unwind": args.unwind, "timeout": args.timeout,
                  "overflow_check": args.overflow_check,
                  "always_on": ["--compact-trace", "--no-unwinding-assertions",
                                "--no-div-by-zero-check"]},
        "jobs": args.jobs,
        "cpu_count": os.cpu_count(),
        "loadavg_start": os.getloadavg(),
        "tasks_this_invocation": len(tasks),
        "started": time.strftime("%Y-%m-%d %H:%M:%S"),
    }
    with open(meta_path, "w") as f:
        json.dump(meta, f, indent=2)

    print(f"[{args.run_name}] {len(tasks)} tasks, jobs={args.jobs}, "
          f"unwind={args.unwind}, timeout={args.timeout}s, "
          f"overflow-check={'ON' if args.overflow_check else 'OFF'}", flush=True)

    counts = {}
    done = 0
    with ProcessPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(run_timed, t) for t in tasks]
        for fut in as_completed(futs):
            _, verdict, _ = fut.result()
            counts[verdict] = counts.get(verdict, 0) + 1
            done += 1
            if done % 200 == 0:
                print(f"  [{done}/{len(tasks)}] {counts}", flush=True)

    meta["loadavg_end"] = os.getloadavg()
    meta["finished"] = time.strftime("%Y-%m-%d %H:%M:%S")
    with open(meta_path, "w") as f:
        json.dump(meta, f, indent=2)

    rows = write_summary(out_root, os.path.join(run_dir, "summary.csv"))
    print(f"Done. summary.csv rows: {len(rows)}; this invocation: {counts}", flush=True)


if __name__ == "__main__":
    main()
