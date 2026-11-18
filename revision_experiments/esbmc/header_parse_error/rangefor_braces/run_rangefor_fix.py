"""
run_rangefor_fix.py
===================
Third pass after the header and fast-I/O fixes: works around an ESBMC 8.0
frontend bug with range-based for loops whose body has no braces.

    for (auto &x : a) cin >> x;        // ESBMC aborts
    for (auto &x : a) { cin >> x; }    // verifies normally

Depending on the body, ESBMC aborts with "unexpected function argument: code",
"assignment statement takes two operands", "postincrement takes one
argument", "ifthenelse takes two or three operands", etc.

Input set: programs whose verdict is ERROR after the fast-I/O stage and that
contain a brace-less range-for. Source: the latest edited copy of each file
(fastio_removed/cpp, then ../cpp, then derived/cpp).

The edit adds "{ " before each brace-less range-for body and " }" after it,
on the same lines, so line numbers do not move. A small statement parser
finds the body's extent (simple statement, braced block, nested if/else,
for, while, do-while).

Check: each original and edited file is compiled with g++ -O1 -c and the
disassembly compared. Adding braces around a single statement does not
change the program, so the code must be identical; manifest.csv records
the result (codegen_identical) and files that fail the check are not run.

Run from the repository root:

    python3.11 revision_experiments/esbmc/header_parse_error/rangefor_braces/run_rangefor_fix.py --jobs 16
"""

import argparse
import csv
import json
import os
import re
import subprocess
import sys
import tempfile
import time
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor, as_completed

HERE = os.path.dirname(os.path.abspath(__file__))
HEADER_DIR = os.path.dirname(HERE)
REPO = os.path.dirname(os.path.dirname(os.path.dirname(HEADER_DIR)))
sys.path.insert(0, os.path.join(REPO, "scripts"))
sys.path.insert(0, os.path.dirname(HEADER_DIR))
sys.path.insert(0, HEADER_DIR)
import run_esbmc_config as RC  # noqa: E402
import run_header_fix as H  # noqa: E402

SOURCE_DIRS = [os.path.join(HEADER_DIR, "fastio_removed", "cpp"),
               os.path.join(HEADER_DIR, "cpp"),
               H.CPP_ROOT]
IDENT = re.compile(r"[A-Za-z_]\w*")


# ---------------------------------------------------------------- parsing

def mask(src):
    """Blank out comments, string/char literals and preprocessor lines,
    keeping every offset, so the parser only sees code."""
    out = list(src)
    i, n = 0, len(src)
    line_start = True
    while i < n:
        c = src[i]
        if line_start and c in " \t":
            i += 1
            continue
        if line_start and c == "#":           # preprocessor line (with \ continuations)
            j = i
            while j < n and not (src[j] == "\n" and src[j - 1] != "\\"):
                out[j] = " "
                j += 1
            i = j
            continue
        line_start = c == "\n"
        if src.startswith("//", i):
            j = src.find("\n", i)
            j = n if j < 0 else j
            for k in range(i, j):
                out[k] = " "
            i = j
        elif src.startswith("/*", i):
            j = src.find("*/", i + 2)
            j = n if j < 0 else j + 2
            for k in range(i, j):
                if src[k] != "\n":
                    out[k] = " "
            i = j
        elif c in "\"'":
            if c == "'" and i > 0 and src[i - 1].isalnum():   # digit separator 1'000
                i += 1
                continue
            j = i + 1
            while j < n and src[j] != c:
                j += 2 if src[j] == "\\" else 1
            for k in range(i + 1, min(j, n)):
                out[k] = " "
            i = j + 1
        else:
            i += 1
    return "".join(out)


def skip_ws(m, i):
    while i < len(m) and m[i].isspace():
        i += 1
    return i


def match_close(m, i):
    """m[i] is an opening bracket; return index just past its match."""
    pairs = {"(": ")", "[": "]", "{": "}"}
    stack = [pairs[m[i]]]
    j = i + 1
    while j < len(m) and stack:
        c = m[j]
        if c in pairs:
            stack.append(pairs[c])
        elif c in ")]}":
            if c != stack[-1]:
                raise ValueError(f"bracket mismatch at {j}")
            stack.pop()
        j += 1
    if stack:
        raise ValueError("unclosed bracket")
    return j


def word_at(m, i):
    w = IDENT.match(m, i)
    return w.group(0) if w else ""


def statement_end(m, i):
    """Return the index just past the statement starting at i."""
    i = skip_ws(m, i)
    w = word_at(m, i)
    if m[i] == "{":
        return match_close(m, i)
    if w in ("for", "while", "switch"):
        p = skip_ws(m, i + len(w))
        return statement_end(m, match_close(m, p))
    if w == "if":
        p = skip_ws(m, i + 2)
        if word_at(m, p) == "constexpr":
            p = skip_ws(m, p + len("constexpr"))
        end = statement_end(m, match_close(m, p))
        k = skip_ws(m, end)
        if word_at(m, k) == "else":
            return statement_end(m, k + 4)
        return end
    if w == "do":
        end = statement_end(m, i + 2)
        k = skip_ws(m, end)
        if word_at(m, k) != "while":
            raise ValueError("do without while")
        p = match_close(m, skip_ws(m, k + 5))
        p = skip_ws(m, p)
        if m[p] != ";":
            raise ValueError("do-while without ;")
        return p + 1
    # expression / declaration / return / break ...: up to ; at depth 0
    j = i
    while j < len(m):
        c = m[j]
        if c in "([{":
            j = match_close(m, j)
            continue
        if c == ";":
            return j + 1
        if c in ")]}":
            raise ValueError(f"unexpected {c} at {j}")
        j += 1
    raise ValueError("statement without ;")


def is_range_for_header(h):
    """h is the text between the parentheses of a for. Range-for has no ;
    and a single ':' at depth 0 (not '::')."""
    depth = 0
    i = 0
    found = False
    while i < len(h):
        c = h[i]
        if c in "([{<" and c != "<":
            depth += 1
        elif c in ")]}":
            depth -= 1
        elif depth == 0 and c == ";":
            return False
        elif depth == 0 and c == ":":
            if h[i:i + 2] == "::":
                i += 2
                continue
            if i > 0 and h[i - 1] == ":":
                i += 1
                continue
            found = True
        i += 1
    return found


def brace_rangefor(src):
    """Return (new_src, n_wrapped)."""
    m = mask(src)
    inserts = []                                   # (offset, text)
    for fm in re.finditer(r"\bfor\b", m):
        p = skip_ws(m, fm.end())
        if p >= len(m) or m[p] != "(":
            continue
        close = match_close(m, p)
        if not is_range_for_header(m[p + 1:close - 1]):
            continue
        body = skip_ws(m, close)
        if m[body] == "{":
            continue
        end = statement_end(m, body)
        inserts.append((body, "{ "))
        inserts.append((end, " }"))
    out = src
    for off, text in sorted(inserts, key=lambda t: t[0], reverse=True):
        out = out[:off] + text + out[off:]
    return out, len(inserts) // 2


# ----------------------------------------------------------------- checks

def disasm(path, workdir):
    obj = os.path.join(workdir, os.path.basename(path) + ".o")
    r = subprocess.run(["g++", "-std=gnu++17", "-O1", "-w", "-c", path, "-o", obj],
                       stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=120)
    if r.returncode != 0:
        return None
    d = subprocess.run(["objdump", "-d", "--no-show-raw-insn", obj],
                       stdout=subprocess.PIPE, timeout=60).stdout.decode()
    return "\n".join(d.split("\n")[3:])           # drop the header with the file name


def check_codegen(orig_path, new_path):
    with tempfile.TemporaryDirectory() as tmp:
        a_dir, b_dir = os.path.join(tmp, "a"), os.path.join(tmp, "b")
        os.makedirs(a_dir)
        os.makedirs(b_dir)
        a = disasm(orig_path, a_dir)
        if a is None:
            return "orig_no_compile"
        b = disasm(new_path, b_dir)
        if b is None:
            return "edited_no_compile"
        return "identical" if a == b else "DIFFERENT"


def latest_source(sid):
    for d in SOURCE_DIRS:
        p = os.path.join(d, sid)
        if os.path.exists(p):
            return p
    raise FileNotFoundError(sid)


def select_and_copy(out_cpp):
    stage = os.path.join(HEADER_DIR, "stage_verdicts.csv")
    manifest, pending = [], []
    for r in csv.DictReader(open(stage)):
        if r["2_header_fastio"] != "ERROR":
            continue
        sid = r["sample_id"]
        src_path = latest_source(sid)
        src = open(src_path, errors="replace").read()
        try:
            new_src, n = brace_rangefor(src)
        except ValueError as e:
            manifest.append({"sample_id": sid, "model": r["model"],
                             "source": os.path.relpath(src_path, REPO),
                             "loops_wrapped": 0, "codegen": f"parse_fail: {e}"})
            continue
        if n == 0:
            continue
        dst = os.path.join(out_cpp, sid)
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        with open(dst, "w") as f:
            f.write(new_src)
        rec = {"sample_id": sid, "model": r["model"],
               "source": os.path.relpath(src_path, REPO),
               "loops_wrapped": n, "codegen": ""}
        manifest.append(rec)
        pending.append((rec, src_path, dst))
    with ThreadPoolExecutor(16) as ex:
        for rec, res in zip([p[0] for p in pending],
                            ex.map(lambda p: check_codegen(p[1], p[2]), pending)):
            rec["codegen"] = res
    return manifest


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--jobs", type=int, default=16)
    ap.add_argument("--unwind", type=int, default=10)
    ap.add_argument("--timeout", type=int, default=60)
    ap.add_argument("--prepare-only", action="store_true",
                    help="write cpp/ and manifest.csv, skip ESBMC")
    args = ap.parse_args()

    os.chdir(REPO)
    out_cpp = os.path.join(HERE, "cpp")
    out_json = os.path.join(HERE, "json")

    manifest = select_and_copy(out_cpp)
    with open(os.path.join(HERE, "manifest.csv"), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=list(manifest[0].keys()))
        w.writeheader()
        w.writerows(manifest)
    counts = {}
    for m in manifest:
        counts[m["codegen"]] = counts.get(m["codegen"], 0) + 1
    print(f"[rangefor_braces] {len(manifest)} files; codegen check: {counts}", flush=True)
    if args.prepare_only:
        return

    # run only files whose edit is shown not to change the compiled code,
    # or whose original does not compile with g++ (cannot be checked)
    runnable = [m for m in manifest if m["codegen"] in ("identical", "orig_no_compile")]
    os.makedirs(out_json, exist_ok=True)
    cfg = {"timeout": args.timeout, "unwind": args.unwind, "overflow_check": True}
    tasks = [t for t in H.build_tasks(runnable, out_cpp, out_json, cfg)
             if not os.path.exists(t["out_json_path"])]

    meta_path = os.path.join(HERE, "meta.json")
    meta = {
        "source_runs": [H.SOURCE_RUN, "header_parse_error", "fastio_removed"],
        "selection": "ERROR after the fast-I/O stage, with a brace-less range-for",
        "n_files": len(manifest),
        "n_run": len(runnable),
        "codegen_check": counts,
        "replacement": "brace-less range-for body -> { body }",
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

    print(f"[rangefor_braces] running {len(tasks)}, jobs={args.jobs}", flush=True)
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
