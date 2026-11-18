"""
run_header_fix.py
=================
Isolates the ESBMC parse errors caused by `#include <bits/stdc++.h>`.

ESBMC 8.0 ships its own models of the C++ standard headers. `bits/stdc++.h`
is a GCC-internal header that ESBMC does not model, so it falls through to
the system libstdc++, which then clashes with ESBMC's models
("redefinition of 'iterator'", "no member named 'tuple_cat'", ...). A file
containing only that include and an empty main() already fails to parse.

Steps:
  1. Take every PARSE_ERROR sample from the reported run (e2_overflow_u10_t60)
     whose source includes <bits/stdc++.h>.
  2. Copy it to cpp/<sample_id>, replacing that one line with the standard
     headers listed in COMPAT_HEADERS (each one checked to parse under ESBMC,
     alone and together). Nothing else in the file changes.
  3. Run ESBMC with the e2 flags (overflow check on, unwind 10, 60 s) and
     write json/, summary.csv and meta.json next to this script.

Line numbers in ESBMC output are shifted by LINE_OFFSET relative to the
original file (for lines after the include).

Headers left out on purpose:
  - optional, variant: parse alone but clash with the others
    ("redefinition of 'hash'")
  - chrono, regex, thread, mutex, atomic, forward_list: fail to parse alone

Run from the repository root:

    python3.11 revision_experiments/esbmc/header_parse_error/run_header_fix.py --jobs 16
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
REPO = os.path.dirname(os.path.dirname(os.path.dirname(HERE)))
sys.path.insert(0, os.path.join(REPO, "scripts"))
sys.path.insert(0, os.path.dirname(HERE))
import run_esbmc as R  # noqa: E402
import run_esbmc_config as RC  # noqa: E402

SOURCE_RUN = "e2_overflow_u10_t60"
CPP_ROOT = os.path.join(REPO, "derived", "cpp")

COMPAT_HEADERS = [
    "cassert", "cctype", "cfloat", "climits", "cmath", "cstdint", "cinttypes",
    "cstdio", "cstdlib", "cstring", "ctime",
    "iostream", "istream", "ostream", "ios", "iomanip", "sstream", "fstream",
    "streambuf", "string", "string_view",
    "vector", "array", "list", "deque", "queue", "stack", "map", "set",
    "unordered_map", "unordered_set", "bitset",
    "algorithm", "numeric", "functional", "utility", "iterator", "memory",
    "tuple", "limits", "random", "complex", "valarray",
    "stdexcept", "exception", "typeinfo", "type_traits", "initializer_list",
    "numbers", "any",
]
REPLACEMENT = (
    ["// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers"]
    + [f"#include <{h}>" for h in COMPAT_HEADERS]
)
LINE_OFFSET = len(REPLACEMENT) - 1

BITS_RE = re.compile(r"^[ \t]*#[ \t]*include[ \t]*<bits/stdc\+\+\.h>.*$", re.M)
INCLUDE_RE = re.compile(r'^[ \t]*#[ \t]*include[ \t]*[<"]([^>"]+)[>"]', re.M)


def select_and_copy(out_cpp):
    """Copy the bits/stdc++.h parse-error files with the header replaced."""
    summary = os.path.join(REPO, "revision_experiments", "esbmc", "runs",
                           SOURCE_RUN, "summary.csv")
    manifest = []
    for r in csv.DictReader(open(summary)):
        if r["verdict"] != "PARSE_ERROR":
            continue
        with open(os.path.join(CPP_ROOT, r["sample_id"]), errors="replace") as f:
            src = f.read()
        if not BITS_RE.search(src):
            continue
        new_src = BITS_RE.sub(lambda _: "\n".join(REPLACEMENT), src)
        dst = os.path.join(out_cpp, r["sample_id"])
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w") as f:
            f.write(new_src)
        others = sorted(set(INCLUDE_RE.findall(src)) - {"bits/stdc++.h"})
        manifest.append({
            "sample_id": r["sample_id"],
            "model": r["model"],
            "generation": r["generation"],
            "e2_verdict": r["verdict"],
            "other_includes": "|".join(others),
        })
    return manifest


def build_tasks(manifest, out_cpp, out_json, cfg):
    tasks = []
    for m in manifest:
        sid = m["sample_id"]
        fn = os.path.basename(sid)
        tasks.append({
            "cpp_path": os.path.join(out_cpp, sid),
            "out_json_path": os.path.join(out_json, sid + ".json"),
            "prob_key": R.normalize("_".join(fn.split("_")[1:]).replace(".cpp", "")),
            "label": sid,
            **cfg,
        })
    return tasks


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
    tasks = build_tasks(manifest, out_cpp, out_json, cfg)
    tasks = [t for t in tasks if not os.path.exists(t["out_json_path"])]  # resume

    meta_path = os.path.join(HERE, "meta.json")
    meta = {
        "source_run": SOURCE_RUN,
        "selection": "e2 PARSE_ERROR files that include <bits/stdc++.h>",
        "n_files": len(manifest),
        "replacement_headers": COMPAT_HEADERS,
        "line_offset": LINE_OFFSET,
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

    print(f"[header_parse_error] {len(manifest)} files, {len(tasks)} to run, "
          f"jobs={args.jobs}", flush=True)

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
