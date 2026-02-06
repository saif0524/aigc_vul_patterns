#!/usr/bin/env python3
"""
Merge all analysis results into a master CSV.
Joins: tests + problem_tags + cppcheck_summary (+ clang_tidy_summary if available)
"""

import re
import pandas as pd
from pathlib import Path

WORKSPACE = Path(__file__).resolve().parent.parent
RAW_CSV = WORKSPACE / "results" / "raw_csv"


def normalize_problem_key(s):
    """Normalize problem key for matching across different formats."""
    s = str(s).strip()
    s = re.sub(r'[.\s]+', '_', s)
    s = re.sub(r'_+', '_', s)
    return s


def main():
    # Load tests
    tests_path = RAW_CSV / "tests_all.csv"
    if not tests_path.exists():
        print(f"ERROR: {tests_path} not found. Run parse_tests.py first.")
        return
    tests = pd.read_csv(tests_path)
    print(f"Loaded tests: {len(tests)} rows")
    
    # Load problem tags
    tags_path = RAW_CSV / "problem_tags.csv"
    if tags_path.exists():
        tags = pd.read_csv(tags_path)
        print(f"Loaded tags: {len(tags)} rows")
    else:
        print("WARNING: problem_tags.csv not found, skipping tags")
        tags = None
    
    # Load cppcheck summary
    cppcheck_path = RAW_CSV / "cppcheck_summary.csv"
    if cppcheck_path.exists():
        cppcheck = pd.read_csv(cppcheck_path)
        print(f"Loaded cppcheck: {len(cppcheck)} rows")
    else:
        print("WARNING: cppcheck_summary.csv not found, skipping cppcheck")
        cppcheck = None
    
    # Load clang-tidy summary (optional)
    clang_path = RAW_CSV / "clang_tidy_summary.csv"
    if clang_path.exists():
        clang = pd.read_csv(clang_path)
        print(f"Loaded clang-tidy: {len(clang)} rows")
    else:
        print("NOTE: clang_tidy_summary.csv not found, skipping clang-tidy")
        clang = None
    
    # Build master from tests
    master = tests.copy()
    
    # Ensure we have model/gen columns
    if "model" not in master.columns and "file" in master.columns:
        # Extract from file path: model/gen/batch/filename
        def extract_model_gen(filepath):
            parts = Path(filepath).parts
            # Find position after 'analysis/tests/' or similar
            try:
                # Path like: gemma/gen_1/00000/file.cpp.json
                model = parts[0] if len(parts) >= 1 else "unknown"
                gen = parts[1] if len(parts) >= 2 else "unknown"
                return model, gen
            except:
                return "unknown", "unknown"
        
        master[["model", "gen"]] = master["file"].apply(
            lambda x: pd.Series(extract_model_gen(x))
        )
    
    # Merge with tags on problem_key (using normalized keys)
    if tags is not None and "problem_key" in master.columns:
        master["norm_key"] = master["problem_key"].apply(normalize_problem_key)
        tags["norm_key"] = tags["problem_key"].apply(normalize_problem_key)
        tags_renamed = tags.rename(columns={"problem_key": "tags_problem_key", "shard": "tags_shard"})
        master = master.merge(tags_renamed, on="norm_key", how="left")
        master = master.drop(columns=["norm_key", "tags_problem_key", "tags_shard"], errors="ignore")
        matched = master["tags"].notna().sum()
        print(f"After tags merge: {len(master)} rows ({matched} with tags)")
    
    # Create normalized sample_id for merging (strip .cpp extension)
    master["norm_sample_id"] = master["sample_id"].str.replace(".cpp", "", regex=False)
    
    # Merge with cppcheck using sample_id
    if cppcheck is not None:
        cppcheck["norm_sample_id"] = cppcheck["sample_id"]  # Already no .cpp
        
        cppcheck_cols = ["norm_sample_id", "total_errors", "warning_count", "num_cwe_types", "has_cwe", "error_count", "style_count", "performance_count"]
        cppcheck_cols = [c for c in cppcheck_cols if c in cppcheck.columns]
        
        cppcheck_sub = cppcheck[cppcheck_cols].copy()
        cppcheck_sub = cppcheck_sub.rename(columns={
            "total_errors": "cppcheck_total",
            "error_count": "cppcheck_errors",
            "warning_count": "cppcheck_warnings",
            "num_cwe_types": "cppcheck_cwe_count",
            "has_cwe": "cppcheck_has_cwe",
            "style_count": "cppcheck_style",
            "performance_count": "cppcheck_perf"
        })
        cppcheck_sub = cppcheck_sub.drop_duplicates(subset=["norm_sample_id"])
        master = master.merge(cppcheck_sub, on="norm_sample_id", how="left")
        matched = master["cppcheck_total"].notna().sum()
        print(f"After cppcheck merge: {len(master)} rows ({matched} matched)")
    
    # Merge with clang-tidy using file column
    if clang is not None:
        clang["norm_sample_id"] = clang["file"]  # Already no .cpp
        
        clang_cols = ["norm_sample_id", "total_diagnostics", "warnings", "errors", "bugprone", "performance", "analyzer"]
        clang_cols = [c for c in clang_cols if c in clang.columns]
        
        clang_sub = clang[clang_cols].copy()
        clang_sub = clang_sub.rename(columns={
            "total_diagnostics": "clang_total",
            "warnings": "clang_warnings",
            "errors": "clang_errors",
            "bugprone": "clang_bugprone",
            "performance": "clang_performance",
            "analyzer": "clang_analyzer"
        })
        clang_sub = clang_sub.drop_duplicates(subset=["norm_sample_id"])
        master = master.merge(clang_sub, on="norm_sample_id", how="left")
        matched = master["clang_total"].notna().sum()
        print(f"After clang-tidy merge: {len(master)} rows ({matched} matched)")
    
    # Clean up temp columns
    master = master.drop(columns=["norm_sample_id"], errors="ignore")
    
    # Save master
    out_path = RAW_CSV / "master_analysis.csv"
    master.to_csv(out_path, index=False)
    print(f"\nWrote {len(master)} rows → {out_path}")
    
    # Print summary stats
    print("\n=== Summary ===")
    if "model" in master.columns:
        print("\nBy model:")
        print(master.groupby("model").size())
    if "compiled" in master.columns:
        print(f"\nCompile rate: {master['compiled'].mean():.1%}")
    if "has_tests" in master.columns:
        print(f"Has tests: {master['has_tests'].mean():.1%}")


if __name__ == "__main__":
    main()
