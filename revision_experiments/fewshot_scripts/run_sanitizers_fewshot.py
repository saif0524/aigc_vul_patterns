#!/usr/bin/env python3
"""ASan + UBSan on the few-shot programs. Reuses compile_and_test_sanitized() from
scripts/run_sanitizers.py, so flags, per-test timeout (30 s), test cases (public tests)
and the CWE mapping are the ones used for the paper.

    python3.11 revision_experiments/fewshot_scripts/run_sanitizers_fewshot.py --jobs 8

For each program: compile with -fsanitize=address,undefined, run every public test,
record correctness and any sanitizer report. The same run gives the test pass rate.

Differences from the main script:
  * The task's shard (which testcases file to read) and its exact name come from the
    generation JSON row (the .cpp number is the row index) and sample_tasks.csv, not
    from the folder or file name. The main script's file-name lookup loses tasks whose
    name has characters outside [A-Za-z0-9 ._-]; here they are found. Programs whose
    task still has no tests are marked tests_found=0 in summary.csv.
  * Sanitized binaries are deleted after each program (--keep-bins keeps them).

Output (revision_experiments/sanitizers_fewshot/runs/<run-name>/):
    json/<model>/gen_N/<file>.cpp.json   per-program result, as in analysis/sanitizers
    summary.csv, meta.json (one entry per invocation), run.log (appended every run)
"""
import csv
import json
import os
import shutil
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed

import common

sys.path.insert(0, str(common.REPO / "scripts"))
import run_sanitizers as R  # noqa: E402

SAMPLE = common.REPO / "revision_experiments" / "fewshot_100_sample"
BIN_ROOT = common.REPO / "revision_experiments" / "bin_sanitized_fewshot"
OUT_BASE = common.REPO / "revision_experiments" / "sanitizers_fewshot" / "runs"


def load_shards():
    with open(SAMPLE / "sample_tasks.csv", newline="", encoding="utf-8") as f:
        return {r["problem_name"]: int(r["shard"]) for r in csv.DictReader(f)}


def task_name(model, gen, cpp_path, cache={}):
    """Exact task name of a program, from its row in the generation JSON."""
    key = (model, gen)
    if key not in cache:
        cache[key] = json.load(open(SAMPLE / "generations" / model / gen / "AIGC_fewshot-sample.json",
                                    encoding="utf-8"))
    return cache[key][int(cpp_path.name[:4])]["name"]


def run_one(task, keep_bins):
    t0 = time.monotonic()
    R.compile_and_test_sanitized(task)
    path = task["out_json_path"]
    with open(path) as f:
        d = json.load(f)
    d["runtime_seconds"] = round(time.monotonic() - t0, 2)
    d["task_name"] = task["task_name"]
    with open(path, "w") as f:
        json.dump(d, f, indent=2)
    if not keep_bins and os.path.exists(task["bin_path"]):
        os.remove(task["bin_path"])
    return d["compiled"], d["any_sanitizer_triggered"], d["n_tests"]


def main():
    ap = common.base_parser("ASan/UBSan on few-shot programs", 8)
    ap.add_argument("--run-name", default="asan_ubsan_t30")
    ap.add_argument("--keep-bins", action="store_true")
    a = ap.parse_args()

    os.chdir(common.REPO)                       # run_sanitizers reads data/testcases/ relatively
    run_dir = a.out_root or OUT_BASE / a.run_name
    out_json = run_dir / "json"
    common.start_log(run_dir / "run.log")

    shards = load_shards()
    tasks = []
    for p in common.collect(a.models, a.gens, a.limit):
        model, gen = p.parent.parent.name, p.parent.name
        out = out_json / model / gen / (p.name + ".json")
        if a.skip_existing and out.exists():
            continue
        name = task_name(model, gen, p, {})
        tasks.append({
            "cpp_path": str(p), "bin_path": str(BIN_ROOT / model / gen / p.stem),
            "out_json_path": str(out), "prob_key": R.normalize(name), "task_name": name,
            "shard": shards[name], "label": f"{model}/{gen}/{p.name}",
        })

    t_start, load_start = time.strftime("%Y-%m-%d %H:%M:%S"), os.getloadavg()
    print(f"[sanitizers] {len(tasks)} programs, {a.jobs} workers, per-test timeout {R.TIMEOUT}s -> {run_dir}", flush=True)
    compiled = triggered = done = 0
    with ProcessPoolExecutor(max_workers=a.jobs) as ex:
        for fut in as_completed([ex.submit(run_one, t, a.keep_bins) for t in tasks]):
            c, s, _ = fut.result()
            done += 1
            compiled += int(c)
            triggered += int(s)
            if done % 25 == 0 or done == len(tasks):
                print(f"  [{done}/{len(tasks)}] compiled={compiled} sanitizer_triggered={triggered}", flush=True)
    if not a.keep_bins:
        shutil.rmtree(BIN_ROOT, ignore_errors=True)

    rows = []
    for jf in sorted(out_json.glob("*/gen_*/*.cpp.json")):
        d = json.loads(jf.read_text())
        rel = jf.relative_to(out_json)
        n, passed = d["n_tests"], d["n_passed"]
        rows.append({
            "sample_id": str(rel)[:-len(".json")], "model": rel.parts[0], "generation": rel.parts[1],
            "task_name": d.get("task_name", ""), "compiled": int(d["compiled"]), "tests_found": int(n > 0),
            "n_tests": n, "n_passed": passed, "pass_rate": round(passed / n, 4) if n else "",
            "passed_all": int(n > 0 and passed == n), "n_timeout": d["n_timeout"],
            "n_sanitizer_triggered": d["n_sanitizer_triggered"],
            "any_sanitizer_triggered": int(d["any_sanitizer_triggered"]),
            "cwes": "|".join(d["all_sanitizer_cwes"]), "runtime_seconds": d.get("runtime_seconds", 0),
        })
    if rows:
        with open(run_dir / "summary.csv", "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(rows[0]))
            w.writeheader()
            w.writerows(rows)
    common.append_meta(run_dir / "meta.json", {
        "started": t_start, "finished": time.strftime("%Y-%m-%d %H:%M:%S"),
        "flags": R.SANITIZER_COMPILE_FLAGS, "per_test_timeout_s": R.TIMEOUT, "jobs": a.jobs,
        "models": a.models or common.MODELS, "gens": a.gens, "limit": a.limit,
        "programs_this_run": len(tasks), "compiled": compiled, "sanitizer_triggered": triggered,
        "loadavg_start": load_start, "loadavg_end": os.getloadavg(), "cpu_count": os.cpu_count()})
    print(f"Done. compiled={compiled}/{len(tasks)}, sanitizer triggered={triggered}; summary.csv rows: {len(rows)}")


if __name__ == "__main__":
    main()
