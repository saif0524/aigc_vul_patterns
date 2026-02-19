"""
parse_esbmc.py
==============
Parse per-program ESBMC JSON results into analysis-ready CSVs.

Outputs:
    results/raw_csv/esbmc_summary.csv
        One row per program: model, gen, batch, problem_key, verdict,
        n_violations, cwes, parse_error, timeout

    results/raw_csv/esbmc_violations.csv
        One row per (program, violation): violation text and mapped CWEs

    results/raw_csv/esbmc_vs_static.csv  (if master_analysis.csv exists)
        Merged view: static-analysis warnings + ESBMC verdicts per program

    results/raw_csv/verification_cross_reference.csv
        Cross-tool comparison: cppcheck CWEs vs sanitizer CWEs vs ESBMC CWEs
        per file (three-layer ground-truth pyramid)

Usage:
    # Baseline run (analysis/esbmc/ → esbmc_summary.csv)
    python scripts/parse_esbmc.py --mode full

    # Overflow-check run
    python scripts/parse_esbmc.py --mode full --tag esbmc_overflow

    # Deep-unwind run
    python scripts/parse_esbmc.py --mode full --tag esbmc_deep
"""

import os
import re
import json
import argparse
import csv

MODELS = ["gemma", "llama", "qwen"]
GENS = ["gen_1", "gen_2", "gen_3"]
HUMAN_SOLNS = ["soln1", "soln2"]

# Re-scan stderr for property violations that run_esbmc.py may have missed
ESBMC_CWE_MAP = {
    "array bounds violated":          "CWE-119",
    "array_bounds":                   "CWE-119",
    "buffer overflow":                "CWE-120",
    "dereference failure":            "CWE-476",
    "null pointer":                   "CWE-476",
    "NULL pointer":                   "CWE-476",
    "division by zero":               "CWE-369",
    "arithmetic overflow":            "CWE-190",
    "overflow on":                    "CWE-190",
    "signed integer overflow":        "CWE-190",
    "unsigned integer overflow":      "CWE-190",
    "memory-leak":                    "CWE-401",
    "memory leak":                    "CWE-401",
    "double free":                    "CWE-415",
    "use after free":                 "CWE-416",
    "invalid pointer":                "CWE-825",
    "dynamic object bounds":          "CWE-119",
    "same object violation":          "CWE-119",
    "access to object out of bounds": "CWE-119",
}


DEFAULT_TAG = "esbmc"


def get_analysis_root(mode, tag=DEFAULT_TAG):
    if mode == "demo":
        return f"demo/demo_analysis/{tag}"
    return f"analysis/{tag}"


def infer_model_gen(rel_path):
    """Extract model and generation from relative path."""
    parts = rel_path.split(os.sep)
    if parts[0] == "human":
        return "human", parts[1]  # human, soln1/soln2
    return parts[0], parts[1]     # gemma, gen_1 etc.


def rescan_for_cwes(stderr_text, stdout_text, violations):
    """Re-scan all available text for CWE-mappable property violations."""
    combined = (stderr_text or "") + "\n" + (stdout_text or "")
    for v in (violations or []):
        combined += "\n" + v

    cwes = set()
    for pattern, cwe in ESBMC_CWE_MAP.items():
        if pattern.lower() in combined.lower():
            cwes.add(cwe)
    return sorted(cwes)


def collect_json_files(analysis_root):
    """Walk the analysis directory and yield (rel_path, full_path)."""
    for root, _dirs, files in os.walk(analysis_root):
        for fname in files:
            if not fname.endswith(".json"):
                continue
            full_path = os.path.join(root, fname)
            rel = os.path.relpath(full_path, analysis_root)
            yield rel, full_path


def parse_all(analysis_root):
    """Parse all ESBMC result JSONs into summary and violation rows."""
    summary_rows = []
    violation_rows = []

    for rel_path, json_path in collect_json_files(analysis_root):
        try:
            with open(json_path) as f:
                data = json.load(f)
        except (json.JSONDecodeError, OSError):
            continue

        model, gen = infer_model_gen(rel_path)
        parts = rel_path.split(os.sep)
        batch = parts[2] if len(parts) > 3 else ""
        # filename: strip trailing .json; keep .cpp for sample_id consistency
        filename = parts[-1]
        if filename.endswith(".json"):
            filename = filename[:-5]  # "foo.cpp.json" -> "foo.cpp"

        sample_id = f"{model}/{gen}/{batch}/{filename}" if model != "human" \
            else f"human/{gen}/{batch}/{filename}"

        verdict = data.get("verdict", "ERROR")
        violations = data.get("violations", [])
        stored_cwes = data.get("cwes", [])

        # Re-scan for CWEs from all text (stderr, stdout, violations)
        rescanned_cwes = rescan_for_cwes(
            data.get("stderr_head", ""),
            data.get("stdout_head", ""),
            violations,
        )
        # Merge stored + rescanned
        all_cwes = sorted(set(stored_cwes) | set(rescanned_cwes))

        summary_rows.append({
            "sample_id": sample_id,
            "model": model,
            "generation": gen,
            "batch": batch,
            "problem_key": data.get("problem_key", ""),
            "verdict": verdict,
            "n_violations": len(violations),
            "cwes": "|".join(all_cwes),
            "parse_error": data.get("parse_error", False),
            "timeout": data.get("timeout", False),
        })

        for i, viol in enumerate(violations):
            violation_rows.append({
                "sample_id": sample_id,
                "model": model,
                "generation": gen,
                "problem_key": data.get("problem_key", ""),
                "violation_idx": i,
                "violation_text": viol,
                "cwes": "|".join(all_cwes),
            })

    return summary_rows, violation_rows


def write_csv(rows, path, fieldnames):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)
    print(f"  Wrote {len(rows)} rows -> {path}")


def merge_with_master(summary_rows, master_path, output_path):
    """Merge ESBMC results with master_analysis.csv using sample_id."""
    if not os.path.exists(master_path):
        print(f"  Skipping merge: {master_path} not found")
        return

    esbmc_by_id = {r["sample_id"]: r for r in summary_rows}

    master = {}
    with open(master_path) as f:
        reader = csv.DictReader(f)
        master_fields = list(reader.fieldnames)
        for row in reader:
            master[row["sample_id"]] = row

    esbmc_fields = [
        "esbmc_verdict", "esbmc_n_violations", "esbmc_cwes",
        "esbmc_parse_error", "esbmc_timeout",
    ]
    merged_fields = master_fields + esbmc_fields
    merged_rows = []
    matched = 0

    for sid, mrow in master.items():
        out = dict(mrow)
        em = esbmc_by_id.get(sid)
        if em:
            matched += 1
            out["esbmc_verdict"] = em["verdict"]
            out["esbmc_n_violations"] = em["n_violations"]
            out["esbmc_cwes"] = em["cwes"]
            out["esbmc_parse_error"] = em["parse_error"]
            out["esbmc_timeout"] = em["timeout"]
        else:
            for ef in esbmc_fields:
                out[ef] = ""
        merged_rows.append(out)

    print(f"  Merged {matched}/{len(master)} master rows with ESBMC data")
    write_csv(merged_rows, output_path, merged_fields)


def build_verification_cross_reference(
    esbmc_rows, sanitizer_path, cppcheck_path, output_path
):
    """Three-way cross-reference: cppcheck vs sanitizer vs ESBMC per file.

    This is the core ground-truth comparison table for the paper.
    """
    # Index ESBMC by sample_id (both with and without .cpp)
    esbmc_by_id = {}
    for r in esbmc_rows:
        sid = r["sample_id"]
        esbmc_by_id[sid] = r
        esbmc_by_id[sid.replace(".cpp", "")] = r

    # Load sanitizer summary if available
    san_by_id = {}
    if os.path.exists(sanitizer_path):
        with open(sanitizer_path) as f:
            for row in csv.DictReader(f):
                sid = row["sample_id"]
                san_by_id[sid] = row
                san_by_id[sid.replace(".cpp", "")] = row
        print(f"  Loaded {len(san_by_id)//2} sanitizer rows")
    else:
        print(f"  Skipping sanitizer: {sanitizer_path} not found")

    # Load cppcheck detailed if available
    cppcheck_cwes_by_id = {}
    if os.path.exists(cppcheck_path):
        with open(cppcheck_path) as f:
            for row in csv.DictReader(f):
                sid = row["sample_id"]
                cwe = row.get("cwe", "")
                if cwe and cwe != "0":
                    cppcheck_cwes_by_id.setdefault(sid, set()).add(f"CWE-{cwe}")
                    sid_cpp = sid + ".cpp" if not sid.endswith(".cpp") else sid
                    cppcheck_cwes_by_id.setdefault(sid_cpp, set()).add(f"CWE-{cwe}")
        print(f"  Loaded cppcheck CWEs for {len(cppcheck_cwes_by_id)//2} files")
    else:
        print(f"  Skipping cppcheck: {cppcheck_path} not found")

    # Collect all sample_ids across tools
    all_sids = set()
    for sid in esbmc_by_id:
        if sid.endswith(".cpp"):
            all_sids.add(sid)
    for sid in san_by_id:
        if sid.endswith(".cpp"):
            all_sids.add(sid)
    for sid in cppcheck_cwes_by_id:
        if sid.endswith(".cpp"):
            all_sids.add(sid)
        else:
            all_sids.add(sid + ".cpp")

    xref_rows = []
    for sid in sorted(all_sids):
        sid_no_ext = sid.replace(".cpp", "")

        # ESBMC
        em = esbmc_by_id.get(sid) or esbmc_by_id.get(sid_no_ext)
        esbmc_cwes = set()
        esbmc_verdict = ""
        if em:
            esbmc_verdict = em["verdict"]
            if em["cwes"]:
                esbmc_cwes = set(em["cwes"].split("|"))

        # Sanitizer
        san = san_by_id.get(sid) or san_by_id.get(sid_no_ext)
        san_cwes = set()
        san_triggered = False
        if san:
            san_triggered = san.get("any_sanitizer_triggered", "") == "True"
            cwes_str = san.get("sanitizer_cwes", "")
            if cwes_str:
                san_cwes = set(cwes_str.split("|"))

        # Cppcheck
        cpp_cwes = cppcheck_cwes_by_id.get(sid, set()) | \
                   cppcheck_cwes_by_id.get(sid_no_ext, set())

        # Skip files with no findings from any tool
        if not esbmc_cwes and not san_cwes and not cpp_cwes \
                and esbmc_verdict != "FAILED":
            continue

        # Infer model/gen
        parts = sid.split("/")
        model = parts[0] if parts else ""
        gen = parts[1] if len(parts) > 1 else ""

        # Agreement metrics
        all_tool_cwes = esbmc_cwes | san_cwes | cpp_cwes
        confirmed_by_2plus = set()
        for cwe in all_tool_cwes:
            count = sum([
                cwe in cpp_cwes,
                cwe in san_cwes,
                cwe in esbmc_cwes,
            ])
            if count >= 2:
                confirmed_by_2plus.add(cwe)

        xref_rows.append({
            "sample_id": sid,
            "model": model,
            "generation": gen,
            "esbmc_verdict": esbmc_verdict,
            "esbmc_cwes": "|".join(sorted(esbmc_cwes)),
            "sanitizer_triggered": san_triggered,
            "sanitizer_cwes": "|".join(sorted(san_cwes)),
            "cppcheck_cwes": "|".join(sorted(cpp_cwes)),
            "esbmc_only": "|".join(sorted(esbmc_cwes - san_cwes - cpp_cwes)),
            "sanitizer_only": "|".join(sorted(san_cwes - esbmc_cwes - cpp_cwes)),
            "cppcheck_only": "|".join(sorted(cpp_cwes - esbmc_cwes - san_cwes)),
            "confirmed_by_2plus": "|".join(sorted(confirmed_by_2plus)),
            "n_tools_with_findings": sum([
                len(cpp_cwes) > 0,
                len(san_cwes) > 0 or san_triggered,
                len(esbmc_cwes) > 0 or esbmc_verdict == "FAILED",
            ]),
        })

    xref_fields = [
        "sample_id", "model", "generation",
        "esbmc_verdict", "esbmc_cwes",
        "sanitizer_triggered", "sanitizer_cwes",
        "cppcheck_cwes",
        "esbmc_only", "sanitizer_only", "cppcheck_only",
        "confirmed_by_2plus", "n_tools_with_findings",
    ]
    write_csv(xref_rows, output_path, xref_fields)
    return xref_rows


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", required=True, choices=["demo", "full"])
    parser.add_argument(
        "--tag", default=DEFAULT_TAG,
        help=f"ESBMC run tag — must match the --tag used in run_esbmc.py "
             f"(default: {DEFAULT_TAG}). Controls both input directory "
             f"(analysis/<tag>/) and output CSV prefix (<tag>_summary.csv).",
    )
    args = parser.parse_args()

    analysis_root = get_analysis_root(args.mode, args.tag)
    out_dir = "results/raw_csv"

    print(f"Parsing ESBMC results from {analysis_root} ...")
    print(f"Output prefix: {args.tag}_*.csv")
    summary_rows, violation_rows = parse_all(analysis_root)

    if not summary_rows:
        print("No ESBMC results found.")
        return

    # Summary CSV
    summary_fields = [
        "sample_id", "model", "generation", "batch", "problem_key",
        "verdict", "n_violations", "cwes", "parse_error", "timeout",
    ]
    write_csv(summary_rows, f"{out_dir}/{args.tag}_summary.csv", summary_fields)

    # Violations CSV
    violation_fields = [
        "sample_id", "model", "generation", "problem_key",
        "violation_idx", "violation_text", "cwes",
    ]
    write_csv(violation_rows, f"{out_dir}/{args.tag}_violations.csv", violation_fields)

    # Merge with master if available
    master_path = f"{out_dir}/master_analysis.csv"
    merge_path = f"{out_dir}/{args.tag}_vs_static.csv"
    merge_with_master(summary_rows, master_path, merge_path)

    # Three-way cross-reference: cppcheck vs sanitizer vs ESBMC
    sanitizer_path = f"{out_dir}/sanitizer_summary.csv"
    cppcheck_path = f"{out_dir}/cppcheck_detailed.csv"
    xref_path = f"{out_dir}/{args.tag}_cross_reference.csv"
    xref_rows = build_verification_cross_reference(
        summary_rows, sanitizer_path, cppcheck_path, xref_path
    )

    # Print statistics
    verdicts = {}
    for r in summary_rows:
        v = r["verdict"]
        verdicts[v] = verdicts.get(v, 0) + 1

    analyzable = verdicts.get("SUCCESS", 0) + verdicts.get("FAILED", 0)
    total = len(summary_rows)

    print(f"\nESBMC Summary: {total} programs")
    for v in ["SUCCESS", "FAILED", "PARSE_ERROR", "TIMEOUT", "ERROR"]:
        print(f"  {v:20s}: {verdicts.get(v, 0)}")
    print(f"  Coverage (analyzable): {analyzable}/{total} "
          f"({analyzable/max(total,1)*100:.1f}%)")

    # CWE breakdown for FAILED programs
    cwe_counts = {}
    for r in summary_rows:
        if r["verdict"] == "FAILED" and r["cwes"]:
            for cwe in r["cwes"].split("|"):
                if cwe:
                    cwe_counts[cwe] = cwe_counts.get(cwe, 0) + 1

    if cwe_counts:
        print("\nESBMC CWE detections (FAILED programs):")
        for cwe, count in sorted(cwe_counts.items(), key=lambda x: -x[1]):
            print(f"  {cwe}: {count} programs")
    else:
        print("\nNo CWEs mapped from ESBMC violations "
              "(violations may reference internal ESBMC headers)")

    # Cross-reference stats
    if xref_rows:
        n_any = len(xref_rows)
        n_2plus = sum(1 for r in xref_rows if int(r["n_tools_with_findings"]) >= 2)
        n_confirmed = sum(1 for r in xref_rows if r["confirmed_by_2plus"])
        print(f"\nCross-tool verification:")
        print(f"  Files with any finding:        {n_any}")
        print(f"  Flagged by 2+ tools:           {n_2plus}")
        print(f"  CWE confirmed by 2+ tools:     {n_confirmed}")

    # Per-model breakdown
    model_stats = {}
    for r in summary_rows:
        m = r["model"]
        v = r["verdict"]
        if m not in model_stats:
            model_stats[m] = {"total": 0, "SUCCESS": 0, "FAILED": 0,
                              "PARSE_ERROR": 0, "TIMEOUT": 0, "ERROR": 0}
        model_stats[m]["total"] += 1
        model_stats[m][v] = model_stats[m].get(v, 0) + 1

    print("\nPer-model breakdown:")
    print(f"  {'Model':<10} {'Total':>6} {'Success':>8} {'Failed':>8} "
          f"{'Parse':>8} {'Timeout':>8} {'Error':>6}")
    for m in sorted(model_stats):
        s = model_stats[m]
        print(f"  {m:<10} {s['total']:>6} {s['SUCCESS']:>8} {s['FAILED']:>8} "
              f"{s['PARSE_ERROR']:>8} {s['TIMEOUT']:>8} {s['ERROR']:>6}")


if __name__ == "__main__":
    main()
