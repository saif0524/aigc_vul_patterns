#!/usr/bin/env python3
"""ESBMC on the few-shot programs, reusing run_esbmc_one() from scripts/run_esbmc.py
so the command line is the one used for the paper. Defaults are the reported
configuration: unwind 10, 60 s timeout, --overflow-check ON.

    python3.11 revision_experiments/fewshot_scripts/run_esbmc_fewshot.py --jobs 8

Output: revision_experiments/esbmc_fewshot/runs/<run-name>/json/<model>/gen_N/<file>.cpp.json
        .../summary.csv, meta.json, run.log   (a new --run-name gives a new folder; nothing is overwritten)

Do not run other heavy jobs at the same time: ESBMC timeouts depend on machine load.
"""
import csv
import json
import os
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed

import common

sys.path.insert(0, str(common.REPO / "scripts"))
import run_esbmc as R  # noqa: E402


def run_timed(task):
    t0 = time.monotonic()
    label, verdict, cwes = R.run_esbmc_one(task)
    path = task["out_json_path"]
    with open(path) as f:
        data = json.load(f)
    data["runtime_seconds"] = round(time.monotonic() - t0, 2)
    with open(path, "w") as f:
        json.dump(data, f, indent=2)
    return label, verdict, cwes


def main():
    ap = common.base_parser("ESBMC on few-shot programs", 8)
    ap.add_argument("--unwind", type=int, default=R.DEFAULT_UNWIND)
    ap.add_argument("--timeout", type=int, default=R.DEFAULT_TIMEOUT)
    ap.add_argument("--run-name", default="e2_overflow_u10_t60",
                    help="folder under esbmc_fewshot/runs/ (same name as the full-benchmark reported run)")
    ap.add_argument("--no-overflow-check", dest="overflow_check", action="store_false")
    a = ap.parse_args()

    run_dir = a.out_root or common.ESBMC_ROOT / "runs" / a.run_name
    root = run_dir / "json"
    common.start_log(run_dir / "run.log")
    cfg = {"timeout": a.timeout, "unwind": a.unwind, "overflow_check": a.overflow_check}
    tasks = []
    for p in common.collect(a.models, a.gens, a.limit):
        rel = p.relative_to(common.SRC_ROOT)               # <model>/gen_N/<file>.cpp
        out = root / (str(rel) + ".json")
        if a.skip_existing and out.exists():
            continue
        tasks.append({
            "cpp_path": str(p), "out_json_path": str(out),
            "prob_key": R.normalize("_".join(p.name.split("_")[1:]).replace(".cpp", "")),
            "label": str(rel), **cfg,
        })
    t_start, load_start = time.strftime("%Y-%m-%d %H:%M:%S"), os.getloadavg()
    print(f"[esbmc] {len(tasks)} files, {a.jobs} workers, unwind={a.unwind}, "
          f"timeout={a.timeout}s, overflow-check={'ON' if a.overflow_check else 'OFF'} -> {root}")

    counts = {}
    with ProcessPoolExecutor(max_workers=a.jobs) as ex:
        for i, fut in enumerate(as_completed([ex.submit(run_timed, t) for t in tasks]), 1):
            v = fut.result()[1]
            counts[v] = counts.get(v, 0) + 1
            if i % 50 == 0 or i == len(tasks):
                print(f"  [{i}/{len(tasks)}] {counts}", flush=True)

    rec = {
        "started": t_start, "finished": time.strftime("%Y-%m-%d %H:%M:%S"),
        "esbmc": R.ESBMC_BIN, "unwind": a.unwind, "timeout": a.timeout,
        "overflow_check": a.overflow_check, "jobs": a.jobs, "models": a.models or common.MODELS,
        "files_this_run": len(tasks), "verdicts_this_run": counts,
        "loadavg_start": load_start, "loadavg_end": os.getloadavg(),
        "cpu_count": os.cpu_count()}
    common.append_meta(run_dir / "meta.json", rec)
    common.log_run("0_esbmc_baseline:" + a.run_name, rec)
    rows = []
    for jf in sorted(root.glob("*/gen_*/*.cpp.json")):
        d = json.loads(jf.read_text())
        rel = jf.relative_to(root)
        rows.append({"sample_id": str(rel)[:-len(".json")], "model": rel.parts[0],
                     "generation": rel.parts[1], "verdict": d["verdict"],
                     "cwes": "|".join(d["cwes"]), "runtime_seconds": d.get("runtime_seconds", 0)})
    if rows:
        with open(run_dir / "summary.csv", "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(rows[0]))
            w.writeheader()
            w.writerows(rows)
        print(f"summary.csv: {len(rows)} rows ({run_dir})")


if __name__ == "__main__":
    main()
