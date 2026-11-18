"""
run_fastio_fix.py
=================
Second pass after run_header_fix.py: isolates the ESBMC parse errors caused by
the fast-I/O lines common in contest code:

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

ESBMC 8.0's model of <iostream> declares sync_with_stdio as a non-static
member and has no tie(), so these lines fail with "call to non-static member
function without an object argument" / "no member named 'tie'". They only
change I/O buffering, so removing them does not change the properties ESBMC
checks.

Input set (both from the e2 run, overflow check on, unwind 10, 60 s):
  A. files that include <bits/stdc++.h>, are still PARSE_ERROR after the
     header substitution, and contain a fast-I/O call. Source: ../cpp/
     (header already substituted).
  B. files without <bits/stdc++.h> that are PARSE_ERROR in e2 and contain a
     fast-I/O call. Source: derived/cpp/.

Each fast-I/O call is replaced in place by ((void)0), so statements such as
`cin.tie(0), cout.tie(0);` stay valid and line numbers do not move (beyond
the header offset for set A). std::tie(...) is not touched.

Run from the repository root:

    python3.11 revision_experiments/esbmc/header_parse_error/fastio_removed/run_fastio_fix.py --jobs 16
"""

import argparse
import csv
import json
import os
import re
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed

HERE = os.path.dirname(os.path.abspath(__file__))
HEADER_DIR = os.path.dirname(HERE)
REPO = os.path.dirname(os.path.dirname(os.path.dirname(HEADER_DIR)))
sys.path.insert(0, os.path.join(REPO, "scripts"))
sys.path.insert(0, os.path.dirname(HEADER_DIR))
sys.path.insert(0, HEADER_DIR)
import run_esbmc_config as RC  # noqa: E402
import run_header_fix as H  # noqa: E402

E2_SUMMARY = os.path.join(REPO, "revision_experiments", "esbmc", "runs",
                          H.SOURCE_RUN, "summary.csv")

ARGS = r"\([^()]*\)"
STREAM = r"(?:std\s*::\s*)?(?:cin|cout|cerr)\s*\.\s*tie\s*" + ARGS
SYNC = (r"(?:std\s*::\s*)?(?:(?:ios|ios_base|istream|ostream|iostream)\s*::"
        r"|(?:cin|cout|cerr)\s*\.)\s*sync_with_stdio\s*" + ARGS)
FASTIO_RE = re.compile(
    rf"(?:{STREAM}(?:\s*->\s*sync_with_stdio\s*{ARGS})?|{SYNC})")
# anything left over after substitution (reported, not fixed)
LEFTOVER_RE = re.compile(r"sync_with_stdio|\.\s*tie\s*\(")


def strip_comments(src):
    return re.sub(r"//[^\n]*|/\*.*?\*/", "", src, flags=re.S)


def select_and_copy(out_cpp):
    header_verdicts = {r["sample_id"]: r["verdict"] for r in
                       csv.DictReader(open(os.path.join(HEADER_DIR, "summary.csv")))}
    manifest = []
    for r in csv.DictReader(open(E2_SUMMARY)):
        if r["verdict"] != "PARSE_ERROR":
            continue
        sid = r["sample_id"]
        if sid in header_verdicts:
            if header_verdicts[sid] != "PARSE_ERROR":
                continue
            subset, src_path = "A_header_fixed", os.path.join(HEADER_DIR, "cpp", sid)
        else:
            orig = open(os.path.join(H.CPP_ROOT, sid), errors="replace").read()
            if H.BITS_RE.search(strip_comments(orig)):
                continue  # header file not in the header run; should not happen
            subset, src_path = "B_no_header", os.path.join(H.CPP_ROOT, sid)
        with open(src_path, errors="replace") as f:
            src = f.read()
        if not FASTIO_RE.search(strip_comments(src)):
            continue
        new_src, n_sub = FASTIO_RE.subn("((void)0)", src)
        dst = os.path.join(out_cpp, sid)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w") as f:
            f.write(new_src)
        manifest.append({
            "sample_id": sid,
            "model": r["model"],
            "generation": r["generation"],
            "subset": subset,
            "calls_replaced": n_sub,
            "leftover_fastio": bool(LEFTOVER_RE.search(strip_comments(new_src))),
        })
    return manifest


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=16)
    ap.add_argument("--unwind", type=int, default=10)
    ap.add_argument("--timeout", type=int, default=60)
    args = ap.parse_args()

    os.chdir(REPO)
    out_cpp = os.path.join(HERE, "cpp")
    out_json = os.path.join(HERE, "json")
    os.makedirs(out_json, exist_ok=True)

    manifest = select_and_copy(out_cpp)
    with open(os.path.join(HERE, "manifest.csv"), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(manifest[0].keys()))
        w.writeheader()
        w.writerows(manifest)

    cfg = {"timeout": args.timeout, "unwind": args.unwind, "overflow_check": True}
    tasks = [t for t in H.build_tasks(manifest, out_cpp, out_json, cfg)
             if not os.path.exists(t["out_json_path"])]  # resume

    meta_path = os.path.join(HERE, "meta.json")
    meta = {
        "source_runs": [H.SOURCE_RUN, "header_parse_error"],
        "selection": "PARSE_ERROR files with a fast-I/O call: A = still failing "
                     "after header substitution, B = no <bits/stdc++.h>",
        "n_files": len(manifest),
        "n_A": sum(m["subset"].startswith("A") for m in manifest),
        "n_B": sum(m["subset"].startswith("B") for m in manifest),
        "replacement": "each fast-I/O call -> ((void)0)",
        "esbmc": RC.esbmc_version(),
        "flags": {"unwind": args.unwind, "timeout": args.timeout,
                  "overflow_check": True,
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

    print(f"[fastio_removed] {len(manifest)} files (A={meta['n_A']}, "
          f"B={meta['n_B']}), {len(tasks)} to run, jobs={args.jobs}", flush=True)

    counts, done = {}, 0
    with ProcessPoolExecutor(max_workers=args.jobs) as ex:
        futs = [ex.submit(RC.run_timed, t) for t in tasks]
        for fut in as_completed(futs):
            _, verdict, _ = fut.result()
            counts[verdict] = counts.get(verdict, 0) + 1
            done += 1
            if done % 100 == 0:
                print(f"  [{done}/{len(tasks)}] {counts}", flush=True)

    meta["loadavg_end"] = os.getloadavg()
    meta["finished"] = time.strftime("%Y-%m-%d %H:%M:%S")
    with open(meta_path, "w") as f:
        json.dump(meta, f, indent=2)

    rows = RC.write_summary(out_json, os.path.join(HERE, "summary.csv"))
    print(f"Done. summary.csv rows: {len(rows)}; this invocation: {counts}", flush=True)


if __name__ == "__main__":
    main()
