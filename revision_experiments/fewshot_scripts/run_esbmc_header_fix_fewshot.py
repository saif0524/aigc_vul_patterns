#!/usr/bin/env python3
"""Stage 1 of the ESBMC header fix, on the few-shot programs.

Same method as revision_experiments/esbmc/header_parse_error/run_header_fix.py:
  1. take the few-shot programs that ESBMC reported as PARSE_ERROR (from
     esbmc_fewshot/runs/<source-run>) and that include <bits/stdc++.h>;
  2. copy each with that one line replaced by the ESBMC-compatible headers
     (COMPAT_HEADERS, imported from run_header_fix.py, so the list is identical);
  3. rerun ESBMC with the reported configuration (unwind 10, 60 s, overflow check on).

    python3.11 revision_experiments/fewshot_scripts/run_esbmc_header_fix_fewshot.py --jobs 8

Output (revision_experiments/esbmc_fewshot/header_parse_error/):
    cpp/<model>/gen_N/<file>.cpp        modified sources
    json/<model>/gen_N/<file>.cpp.json  ESBMC results
    manifest.csv, summary.csv, meta.json
Line numbers in ESBMC output are shifted by line_offset (see meta.json) for lines
after the include. Run ESBMC (run_esbmc_fewshot.py) first; do not run other heavy
jobs at the same time.
"""
import argparse
import csv
import json
import os
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed

import common

sys.path.insert(0, str(common.REPO / "scripts"))
sys.path.insert(0, str(common.REPO / "revision_experiments" / "esbmc"))
sys.path.insert(0, str(common.REPO / "revision_experiments" / "esbmc" / "header_parse_error"))
import run_esbmc as R  # noqa: E402
import run_esbmc_config as RC  # noqa: E402
import run_header_fix as H  # noqa: E402

OUT = common.ESBMC_ROOT / "header_parse_error"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--source-run", default="e2_overflow_u10_t60", help="stage 0 run to read")
    ap.add_argument("--models", nargs="+", choices=common.MODELS)
    ap.add_argument("--unwind", type=int, default=10)
    ap.add_argument("--timeout", type=int, default=60)
    ap.add_argument("--no-resume", action="store_true")
    a = ap.parse_args()

    orig = common.ESBMC_ROOT / "runs" / a.source_run / "json"
    common.start_log(OUT / "run.log")
    out_cpp, out_json = OUT / "cpp", OUT / "json"
    manifest = []
    for jf in sorted(orig.glob("*/gen_*/*.cpp.json")):
        rel = jf.relative_to(orig)                     # <model>/gen_N/<file>.cpp.json
        if a.models and rel.parts[0] not in a.models:
            continue
        if json.loads(jf.read_text())["verdict"] != "PARSE_ERROR":
            continue
        sid = str(rel)[:-len(".json")]                 # <model>/gen_N/<file>.cpp
        src = (common.SRC_ROOT / sid).read_text(errors="replace")
        if not H.BITS_RE.search(src):
            continue
        dst = out_cpp / sid
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_text(H.BITS_RE.sub(lambda _: "\n".join(H.REPLACEMENT), src))
        others = sorted(set(H.INCLUDE_RE.findall(src)) - {"bits/stdc++.h"})
        manifest.append({"sample_id": sid, "model": rel.parts[0], "generation": rel.parts[1],
                         "orig_verdict": "PARSE_ERROR", "other_includes": "|".join(others)})
    if not manifest:
        sys.exit("no PARSE_ERROR files with <bits/stdc++.h> found; run run_esbmc_fewshot.py first")
    OUT.mkdir(parents=True, exist_ok=True)
    with open(OUT / "manifest.csv", "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(manifest[0]))
        w.writeheader()
        w.writerows(manifest)

    cfg = {"timeout": a.timeout, "unwind": a.unwind, "overflow_check": True}
    tasks = []
    for m in manifest:
        sid = m["sample_id"]
        t = {"cpp_path": str(out_cpp / sid), "out_json_path": str(out_json / (sid + ".json")),
             "prob_key": R.normalize("_".join(os.path.basename(sid).split("_")[1:]).replace(".cpp", "")),
             "label": sid, **cfg}
        if a.no_resume or not os.path.exists(t["out_json_path"]):
            tasks.append(t)

    meta = {"selection": "few-shot PARSE_ERROR files that include <bits/stdc++.h>",
            "n_files": len(manifest), "replacement_headers": H.COMPAT_HEADERS,
            "line_offset": H.LINE_OFFSET, "esbmc": RC.esbmc_version(),
            "flags": {"unwind": a.unwind, "timeout": a.timeout, "overflow_check": True,
                      "always_on": ["--compact-trace", "--no-unwinding-assertions", "--no-div-by-zero-check"]},
            "jobs": a.jobs, "cpu_count": os.cpu_count(), "loadavg_start": os.getloadavg(),
            "tasks_this_invocation": len(tasks), "started": time.strftime("%Y-%m-%d %H:%M:%S")}
    print(f"[esbmc_header] {len(manifest)} files, {len(tasks)} to run, jobs={a.jobs}", flush=True)

    counts = {}
    with ProcessPoolExecutor(max_workers=a.jobs) as ex:
        for i, fut in enumerate(as_completed([ex.submit(RC.run_timed, t) for t in tasks]), 1):
            v = fut.result()[1]
            counts[v] = counts.get(v, 0) + 1
            if i % 25 == 0 or i == len(tasks):
                print(f"  [{i}/{len(tasks)}] {counts}", flush=True)

    meta["loadavg_end"] = os.getloadavg()
    meta["finished"] = time.strftime("%Y-%m-%d %H:%M:%S")
    meta["source_run"] = a.source_run
    common.append_meta(OUT / "meta.json", meta)
    common.log_run("1_header", {
        "started": meta["started"], "finished": meta["finished"], "esbmc": meta["esbmc"],
        "unwind": a.unwind, "timeout": a.timeout, "overflow_check": True, "jobs": a.jobs,
        "models": a.models or common.MODELS, "files_selected": len(manifest),
        "files_this_run": len(tasks), "verdicts_this_run": counts,
        "loadavg_start": meta["loadavg_start"], "loadavg_end": meta["loadavg_end"],
        "cpu_count": os.cpu_count()})
    rows = RC.write_summary(str(out_json), str(OUT / "summary.csv"))
    print(f"Done. summary.csv rows: {len(rows)}; this invocation: {counts}", flush=True)


if __name__ == "__main__":
    main()
