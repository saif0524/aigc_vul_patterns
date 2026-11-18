#!/usr/bin/env python3
"""Stage 2 of the ESBMC fixes, on the few-shot programs: remove fast-I/O calls.

Same method as revision_experiments/esbmc/header_parse_error/fastio_removed/run_fastio_fix.py
(the regexes are imported from it, so the rewrite is identical):

    ios::sync_with_stdio(false);  cin.tie(nullptr);   ->   ((void)0)

Input set, from the few-shot runs:
  A. PARSE_ERROR after the header substitution (esbmc_fewshot/header_parse_error) and
     containing a fast-I/O call. Source: header_parse_error/cpp (header already replaced).
  B. PARSE_ERROR at stage 0 (esbmc_fewshot/runs/<source-run>), never given a header fix because
     there is no <bits/stdc++.h>, and containing a fast-I/O call. Source: derived_cpp/fewshot.

Run order: run_esbmc_fewshot.py, then run_esbmc_header_fix_fewshot.py, then this.

    python3.11 revision_experiments/fewshot_scripts/run_esbmc_fastio_fix_fewshot.py --jobs 8

Output (revision_experiments/esbmc_fewshot/header_parse_error/fastio_removed/): cpp/, json/,
manifest.csv, summary.csv, meta.json, run.log. Each run also adds a line to esbmc_fewshot/runs.jsonl.
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
for sub in ("header_parse_error", "header_parse_error/fastio_removed"):
    sys.path.insert(0, str(common.REPO / "revision_experiments" / "esbmc" / sub))
import run_esbmc as R  # noqa: E402
import run_esbmc_config as RC  # noqa: E402
import run_header_fix as H  # noqa: E402
import run_fastio_fix as F  # noqa: E402

HEADER = common.ESBMC_ROOT / "header_parse_error"
OUT = HEADER / "fastio_removed"


def verdicts(root):
    out = {}
    for jf in root.glob("*/gen_*/*.cpp.json"):
        out[str(jf.relative_to(root))[:-len(".json")]] = json.loads(jf.read_text())["verdict"]
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--source-run", default="e2_overflow_u10_t60", help="stage 0 run to read")
    ap.add_argument("--models", nargs="+", choices=common.MODELS)
    ap.add_argument("--unwind", type=int, default=10)
    ap.add_argument("--timeout", type=int, default=60)
    ap.add_argument("--no-resume", action="store_true")
    a = ap.parse_args()

    common.start_log(OUT / "run.log")
    stage0 = verdicts(common.ESBMC_ROOT / "runs" / a.source_run / "json")
    header = verdicts(HEADER / "json")
    out_cpp, out_json = OUT / "cpp", OUT / "json"
    manifest = []
    for sid, v0 in sorted(stage0.items()):
        if v0 != "PARSE_ERROR" or (a.models and sid.split("/")[0] not in a.models):
            continue
        if sid in header:
            if header[sid] != "PARSE_ERROR":
                continue
            subset, src_path = "A_header_fixed", HEADER / "cpp" / sid
        else:
            orig = (common.SRC_ROOT / sid).read_text(errors="replace")
            if H.BITS_RE.search(F.strip_comments(orig)):
                print(f"warning: {sid} has <bits/stdc++.h> but no header-fix result; "
                      "run run_esbmc_header_fix_fewshot.py first", file=sys.stderr)
                continue
            subset, src_path = "B_no_header", common.SRC_ROOT / sid
        src = src_path.read_text(errors="replace")
        if not F.FASTIO_RE.search(F.strip_comments(src)):
            continue
        new_src, n_sub = F.FASTIO_RE.subn("((void)0)", src)
        dst = out_cpp / sid
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_text(new_src)
        manifest.append({"sample_id": sid, "model": sid.split("/")[0], "generation": sid.split("/")[1],
                         "subset": subset, "calls_replaced": n_sub,
                         "leftover_fastio": bool(F.LEFTOVER_RE.search(F.strip_comments(new_src)))})
    if not manifest:
        sys.exit("no PARSE_ERROR files with a fast-I/O call; check the earlier stages have run")
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

    meta = {"selection": "few-shot PARSE_ERROR files with a fast-I/O call (A: after header fix, "
                         "B: no <bits/stdc++.h>)",
            "n_files": len(manifest),
            "n_A": sum(m["subset"].startswith("A") for m in manifest),
            "n_B": sum(m["subset"].startswith("B") for m in manifest),
            "replacement": "each fast-I/O call -> ((void)0)", "esbmc": RC.esbmc_version(),
            "flags": {"unwind": a.unwind, "timeout": a.timeout, "overflow_check": True,
                      "always_on": ["--compact-trace", "--no-unwinding-assertions", "--no-div-by-zero-check"]},
            "jobs": a.jobs, "cpu_count": os.cpu_count(), "loadavg_start": os.getloadavg(),
            "tasks_this_invocation": len(tasks), "started": time.strftime("%Y-%m-%d %H:%M:%S")}
    print(f"[esbmc_fastio] {len(manifest)} files (A={meta['n_A']}, B={meta['n_B']}), "
          f"{len(tasks)} to run, jobs={a.jobs}", flush=True)

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
    common.log_run("2_fastio", {
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
