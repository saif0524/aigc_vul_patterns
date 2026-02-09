"""
parse_sanitizers.py
===================
Parse per-program sanitizer JSON results into analysis-ready CSVs.

Outputs:
    results/raw_csv/sanitizer_summary.csv
        One row per program: model, gen, problem_key, compiled, n_tests,
        n_passed, any_sanitizer_triggered, n_sanitizer_triggered,
        sanitizer_errors, sanitizer_cwes

    results/raw_csv/sanitizer_detailed.csv
        One row per (program, test_case): includes per-test sanitizer
        triggers, error types, and CWE mappings

    results/raw_csv/sanitizer_vs_static.csv  (if master_analysis.csv exists)
        Merged view: static analysis warnings + dynamic sanitizer results
        per program, for cross-validation analysis.

Usage:
    python scripts/parse_sanitizers.py --mode full
    python scripts/parse_sanitizers.py --mode demo
"""

import os
import json
import argparse
import csv

MODELS = ["gemma", "llama", "qwen"]
GENS = ["gen_1", "gen_2", "gen_3"]
HUMAN_SOLNS = ["soln1", "soln2"]


def get_analysis_root(mode):
    if mode == "demo":
        return "demo/demo_analysis/demo_sanitizers"
    return "analysis/sanitizers"


def infer_model_gen(rel_path):
    """Extract model and generation from relative path."""
    parts = rel_path.split(os.sep)
    if parts[0] == "human":
        return "human", parts[1]  # human, soln1/soln2
    return parts[0], parts[1]     # gemma, gen_1 etc.


def collect_json_files(analysis_root):
    """Walk the analysis directory and yield (model, gen, batch, json_path)."""
    for root, _dirs, files in os.walk(analysis_root):
        for fname in files:
            if not fname.endswith(".json"):
                continue
            full_path = os.path.join(root, fname)
            rel = os.path.relpath(full_path, analysis_root)
            yield rel, full_path


def parse_all(analysis_root):
    """Parse all sanitizer result JSONs into summary and detail rows."""
    summary_rows = []
    detail_rows = []

    for rel_path, json_path in collect_json_files(analysis_root):
        try:
            with open(json_path) as f:
                data = json.load(f)
        except (json.JSONDecodeError, OSError):
            continue

        model, gen = infer_model_gen(rel_path)
        parts = rel_path.split(os.sep)
        batch = parts[2] if len(parts) > 3 else ""
        filename = parts[-1].replace(".json", "")

        # Build a unique sample ID consistent with the main pipeline
        sample_id = f"{model}/{gen}/{batch}/{filename}" if model != "human" \
            else f"human/{gen}/{batch}/{filename}"

        summary_rows.append({
            "sample_id": sample_id,
            "model": model,
            "generation": gen,
            "batch": batch,
            "problem_key": data.get("problem_key", ""),
            "compiled": data.get("compiled", False),
            "n_tests": data.get("n_tests", 0),
            "n_passed": data.get("n_passed", 0),
            "n_timeout": data.get("n_timeout", 0),
            "any_sanitizer_triggered": data.get("any_sanitizer_triggered", False),
            "n_sanitizer_triggered": data.get("n_sanitizer_triggered", 0),
            "sanitizer_errors": "|".join(data.get("all_sanitizer_errors", [])),
            "sanitizer_cwes": "|".join(data.get("all_sanitizer_cwes", [])),
        })

        for test in data.get("per_test", []):
            detail_rows.append({
                "sample_id": sample_id,
                "model": model,
                "generation": gen,
                "problem_key": data.get("problem_key", ""),
                "test_idx": test.get("test_idx", 0),
                "correct": test.get("correct", False),
                "timeout": test.get("timeout", False),
                "sanitizer_triggered": test.get("sanitizer_triggered", False),
                "sanitizer_errors": "|".join(test.get("sanitizer_errors", [])),
                "sanitizer_cwes": "|".join(test.get("sanitizer_cwes", [])),
                "returncode": test.get("returncode", 0),
            })

    return summary_rows, detail_rows


def write_csv(rows, path, fieldnames):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)
    print(f"  Wrote {len(rows)} rows -> {path}")


def merge_with_master(summary_rows, master_path, output_path):
    """Merge sanitizer results with master_analysis.csv using sample_id."""
    if not os.path.exists(master_path):
        print(f"  Skipping merge: {master_path} not found")
        return

    # Index sanitizer rows by sample_id for O(1) lookup
    san_by_id = {r["sample_id"]: r for r in summary_rows}

    master = {}
    with open(master_path) as f:
        reader = csv.DictReader(f)
        master_fields = list(reader.fieldnames)
        for row in reader:
            master[row["sample_id"]] = row

    san_fields = [
        "san_compiled", "san_n_tests", "san_n_passed",
        "san_any_triggered", "san_n_triggered",
        "san_errors", "san_cwes",
    ]
    merged_fields = master_fields + san_fields
    merged_rows = []
    matched = 0

    for sid, mrow in master.items():
        out = dict(mrow)
        san_match = san_by_id.get(sid)
        if san_match:
            matched += 1
            out["san_compiled"] = san_match["compiled"]
            out["san_n_tests"] = san_match["n_tests"]
            out["san_n_passed"] = san_match["n_passed"]
            out["san_any_triggered"] = san_match["any_sanitizer_triggered"]
            out["san_n_triggered"] = san_match["n_sanitizer_triggered"]
            out["san_errors"] = san_match["sanitizer_errors"]
            out["san_cwes"] = san_match["sanitizer_cwes"]
        else:
            for sf in san_fields:
                out[sf] = ""
        merged_rows.append(out)

    print(f"  Merged {matched}/{len(master)} master rows with sanitizer data")
    write_csv(merged_rows, output_path, merged_fields)


def build_cwe_cross_reference(summary_rows, cppcheck_path, output_path):
    """Cross-reference: per file, which CWEs did cppcheck flag vs ASan confirm?

    Joins on sample_id (normalizing the .cpp extension mismatch).
    Outputs one row per file that has findings from either tool.
    """
    if not os.path.exists(cppcheck_path):
        print(f"  Skipping CWE cross-ref: {cppcheck_path} not found")
        return

    # Index sanitizer results by sample_id (strip .cpp for cppcheck compat)
    san_by_id = {}
    for r in summary_rows:
        sid = r["sample_id"]
        # Master/sanitizer have .cpp, cppcheck does not
        sid_no_ext = sid.replace(".cpp", "")
        san_by_id[sid] = r
        san_by_id[sid_no_ext] = r

    # Collect cppcheck CWEs per sample_id
    cppcheck_cwes = {}  # sample_id -> set of CWE strings
    with open(cppcheck_path) as f:
        reader = csv.DictReader(f)
        for row in reader:
            sid = row["sample_id"]
            cwe = row.get("cwe", "")
            if cwe and cwe != "0":
                cppcheck_cwes.setdefault(sid, set()).add(f"CWE-{cwe}")

    # Build cross-reference rows
    all_sids = set(san_by_id.keys()) | set(cppcheck_cwes.keys())
    xref_rows = []

    for sid in sorted(all_sids):
        san = san_by_id.get(sid)
        cpp_cwes = cppcheck_cwes.get(sid, set())

        # Skip files with no findings from either tool
        san_cwes = set()
        if san and san["sanitizer_cwes"]:
            san_cwes = set(san["sanitizer_cwes"].split("|"))

        if not cpp_cwes and not san_cwes:
            continue

        # Determine model/gen from whichever source has it
        model = san["model"] if san else ""
        gen = san["generation"] if san else ""
        prob = san["problem_key"] if san else ""

        if not model:
            parts = sid.split("/")
            model = parts[0] if parts else ""
            gen = parts[1] if len(parts) > 1 else ""

        xref_rows.append({
            "sample_id": sid,
            "model": model,
            "generation": gen,
            "problem_key": prob,
            "cppcheck_cwes": "|".join(sorted(cpp_cwes)),
            "sanitizer_cwes": "|".join(sorted(san_cwes)),
            "cppcheck_only": "|".join(sorted(cpp_cwes - san_cwes)),
            "sanitizer_only": "|".join(sorted(san_cwes - cpp_cwes)),
            "both": "|".join(sorted(cpp_cwes & san_cwes)),
            "static_confirmed_dynamically": len(cpp_cwes & san_cwes) > 0,
        })

    xref_fields = [
        "sample_id", "model", "generation", "problem_key",
        "cppcheck_cwes", "sanitizer_cwes",
        "cppcheck_only", "sanitizer_only", "both",
        "static_confirmed_dynamically",
    ]
    write_csv(xref_rows, output_path, xref_fields)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--mode", required=True, choices=["demo", "full"])
    args = parser.parse_args()

    analysis_root = get_analysis_root(args.mode)
    out_dir = "results/raw_csv"

    print(f"Parsing sanitizer results from {analysis_root} ...")
    summary_rows, detail_rows = parse_all(analysis_root)

    if not summary_rows:
        print("No sanitizer results found.")
        return

    # Summary CSV
    summary_fields = [
        "sample_id", "model", "generation", "batch", "problem_key",
        "compiled", "n_tests", "n_passed", "n_timeout",
        "any_sanitizer_triggered", "n_sanitizer_triggered",
        "sanitizer_errors", "sanitizer_cwes",
    ]
    write_csv(summary_rows, f"{out_dir}/sanitizer_summary.csv", summary_fields)

    # Detailed CSV
    detail_fields = [
        "sample_id", "model", "generation", "problem_key",
        "test_idx", "correct", "timeout",
        "sanitizer_triggered", "sanitizer_errors", "sanitizer_cwes",
        "returncode",
    ]
    write_csv(detail_rows, f"{out_dir}/sanitizer_detailed.csv", detail_fields)

    # Merge with master if available
    master_path = f"{out_dir}/master_analysis.csv"
    merge_path = f"{out_dir}/sanitizer_vs_static.csv"
    merge_with_master(summary_rows, master_path, merge_path)

    # Per-file CWE cross-reference: cppcheck vs sanitizer
    cppcheck_detailed_path = f"{out_dir}/cppcheck_detailed.csv"
    xref_path = f"{out_dir}/cwe_cross_reference.csv"
    build_cwe_cross_reference(summary_rows, cppcheck_detailed_path, xref_path)

    # Print quick stats
    compiled = sum(1 for r in summary_rows if r["compiled"])
    triggered = sum(1 for r in summary_rows if r["any_sanitizer_triggered"])
    print(f"\nSummary: {len(summary_rows)} programs, "
          f"{compiled} compiled with sanitizers, "
          f"{triggered} triggered ({triggered/max(compiled,1)*100:.1f}%)")

    # CWE breakdown
    cwe_counts = {}
    for r in summary_rows:
        for cwe in r["sanitizer_cwes"].split("|"):
            if cwe:
                cwe_counts[cwe] = cwe_counts.get(cwe, 0) + 1
    if cwe_counts:
        print("\nDynamic CWE detections:")
        for cwe, count in sorted(cwe_counts.items(), key=lambda x: -x[1]):
            print(f"  {cwe}: {count} programs")


if __name__ == "__main__":
    main()
