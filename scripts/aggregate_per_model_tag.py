#!/usr/bin/env python3
"""
Aggregate analysis results per model/gen/tag.
Produces summary statistics broken down by problem tags.
"""

import pandas as pd
from pathlib import Path

WORKSPACE = Path(__file__).resolve().parent.parent
RAW_CSV = WORKSPACE / "results" / "raw_csv"


def main():
    # Load master analysis
    master_path = RAW_CSV / "master_analysis.csv"
    if not master_path.exists():
        print(f"ERROR: {master_path} not found. Run merge_master_all.py first.")
        return
    
    df = pd.read_csv(master_path)
    print(f"Loaded master: {len(df)} rows")
    
    # Ensure required columns - handle 'gen' or 'generation'
    if "generation" in df.columns and "gen" not in df.columns:
        df["gen"] = df["generation"]
    
    required = ["model", "gen"]
    for col in required:
        if col not in df.columns:
            print(f"ERROR: missing column '{col}'")
            return
    
    # === Per-model-gen aggregation ===
    agg_model_gen = df.groupby(["model", "gen"]).agg({
        "compiled": ["sum", "count", "mean"],
        "has_tests": "sum",
    }).reset_index()
    agg_model_gen.columns = ["model", "gen", "compiled_count", "total_files", "compile_rate", "has_tests_count"]
    
    # Add pass rate (only for files with tests)
    if "passed" in df.columns and "total" in df.columns:
        with_tests = df[df["has_tests"] == True].copy()
        if len(with_tests) > 0:
            pass_agg = with_tests.groupby(["model", "gen"]).agg({
                "passed": "sum",
                "total": "sum"
            }).reset_index()
            pass_agg["pass_rate"] = pass_agg["passed"] / pass_agg["total"].replace(0, 1)
            agg_model_gen = agg_model_gen.merge(pass_agg[["model", "gen", "pass_rate"]], on=["model", "gen"], how="left")
    
    # Add cppcheck aggregates
    if "cppcheck_errors" in df.columns:
        cpp_agg = df.groupby(["model", "gen"]).agg({
            "cppcheck_errors": "sum",
            "cppcheck_warnings": "sum",
            "cppcheck_cwe_count": "sum"
        }).reset_index()
        agg_model_gen = agg_model_gen.merge(cpp_agg, on=["model", "gen"], how="left")
    
    # Add clang-tidy aggregates
    if "clang_warnings" in df.columns:
        clang_agg = df.groupby(["model", "gen"]).agg({
            "clang_warnings": "sum",
            "clang_errors": "sum"
        }).reset_index()
        agg_model_gen = agg_model_gen.merge(clang_agg, on=["model", "gen"], how="left")
    
    out_model_gen = RAW_CSV / "agg_per_model_gen.csv"
    agg_model_gen.to_csv(out_model_gen, index=False)
    print(f"Wrote {len(agg_model_gen)} rows → {out_model_gen}")
    
    # === Per-model-gen-tag aggregation ===
    if "tags" in df.columns:
        # Explode tags (pipe-separated list) into rows
        df_exploded = df.copy()
        df_exploded["tags"] = df_exploded["tags"].fillna("").astype(str)
        df_exploded = df_exploded.assign(tag=df_exploded["tags"].str.split(r"\|")).explode("tag")
        df_exploded["tag"] = df_exploded["tag"].str.strip()
        df_exploded = df_exploded[df_exploded["tag"] != ""]
        
        agg_tag = df_exploded.groupby(["model", "gen", "tag"]).agg({
            "compiled": ["sum", "count", "mean"],
            "has_tests": "sum",
        }).reset_index()
        agg_tag.columns = ["model", "gen", "tag", "compiled_count", "total_files", "compile_rate", "has_tests_count"]
        
        # Add pass rate per tag
        if "passed" in df_exploded.columns and "total" in df_exploded.columns:
            with_tests = df_exploded[df_exploded["has_tests"] == True].copy()
            if len(with_tests) > 0:
                pass_agg = with_tests.groupby(["model", "gen", "tag"]).agg({
                    "passed": "sum",
                    "total": "sum"
                }).reset_index()
                pass_agg["pass_rate"] = pass_agg["passed"] / pass_agg["total"].replace(0, 1)
                agg_tag = agg_tag.merge(pass_agg[["model", "gen", "tag", "pass_rate"]], on=["model", "gen", "tag"], how="left")
        
        # Add cppcheck per tag
        if "cppcheck_errors" in df_exploded.columns:
            cpp_agg = df_exploded.groupby(["model", "gen", "tag"]).agg({
                "cppcheck_errors": "sum",
                "cppcheck_warnings": "sum",
                "cppcheck_cwe_count": "sum"
            }).reset_index()
            agg_tag = agg_tag.merge(cpp_agg, on=["model", "gen", "tag"], how="left")
        
        # Add clang-tidy per tag
        if "clang_warnings" in df_exploded.columns:
            clang_agg = df_exploded.groupby(["model", "gen", "tag"]).agg({
                "clang_warnings": "sum",
                "clang_errors": "sum"
            }).reset_index()
            agg_tag = agg_tag.merge(clang_agg, on=["model", "gen", "tag"], how="left")
        
        out_tag = RAW_CSV / "agg_per_model_gen_tag.csv"
        agg_tag.to_csv(out_tag, index=False)
        print(f"Wrote {len(agg_tag)} rows → {out_tag}")
    else:
        print("NOTE: 'tags' column not found, skipping per-tag aggregation")
    
    # Print summary
    print("\n=== Per-model-gen Summary ===")
    print(agg_model_gen.to_string(index=False))


if __name__ == "__main__":
    main()
