#!/usr/bin/env python3
"""
Parse clang-tidy YAML output files into CSV summaries.
Produces:
  - clang_tidy_detailed.csv: One row per diagnostic
  - clang_tidy_summary.csv: One row per source file with aggregated counts
"""

import os
import re
import yaml
from pathlib import Path
from collections import defaultdict

WORKSPACE = Path(__file__).resolve().parent.parent
ANALYSIS_ROOT = WORKSPACE / "analysis" / "clang_tidy"
OUT_DIR = WORKSPACE / "results" / "raw_csv"


def extract_file_info(yaml_path: Path):
    """Extract model/gen/batch/filename from path."""
    rel = yaml_path.relative_to(ANALYSIS_ROOT)
    parts = rel.parts
    # model/gen/batch/filename.yaml
    if len(parts) >= 4:
        model = parts[0]
        gen = parts[1]
        batch = parts[2]
        filename = parts[3].replace(".yaml", "")
        return model, gen, batch, filename
    return None, None, None, None


def extract_problem_key(filename: str) -> str:
    """Extract problem key from filename like 0182_1311_C._Perform_the_Combo"""
    # Remove leading number (index)
    parts = filename.split("_", 1)
    if len(parts) > 1:
        return parts[1]
    return filename


def parse_yaml_file(yaml_path: Path) -> list:
    """Parse a single clang-tidy YAML file and return list of diagnostics."""
    diagnostics = []
    
    try:
        with open(yaml_path, "r", encoding="utf-8", errors="replace") as f:
            content = f.read()
        
        # Handle empty files
        if not content.strip():
            return []
        
        data = yaml.safe_load(content)
        if not data or "Diagnostics" not in data:
            return []
        
        for diag in data.get("Diagnostics", []):
            name = diag.get("DiagnosticName", "unknown")
            level = diag.get("Level", "unknown")
            msg = diag.get("DiagnosticMessage", {})
            message = msg.get("Message", "")
            file_offset = msg.get("FileOffset", 0)
            
            diagnostics.append({
                "diagnostic_name": name,
                "level": level,
                "message": message[:200],  # Truncate long messages
                "file_offset": file_offset,
            })
    except yaml.YAMLError as e:
        print(f"YAML error in {yaml_path}: {e}")
    except Exception as e:
        print(f"Error parsing {yaml_path}: {e}")
    
    return diagnostics


def categorize_diagnostic(name: str) -> str:
    """Categorize diagnostic by type."""
    if name.startswith("clang-diagnostic-"):
        return "compiler-warning"
    elif name.startswith("modernize-"):
        return "modernize"
    elif name.startswith("bugprone-"):
        return "bugprone"
    elif name.startswith("performance-"):
        return "performance"
    elif name.startswith("readability-"):
        return "readability"
    elif name.startswith("cppcoreguidelines-"):
        return "cppcoreguidelines"
    elif name.startswith("cert-"):
        return "cert"
    elif name.startswith("clang-analyzer-"):
        return "analyzer"
    elif name.startswith("misc-"):
        return "misc"
    elif name.startswith("hicpp-"):
        return "hicpp"
    else:
        return "other"


def main():
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    
    yaml_files = list(ANALYSIS_ROOT.rglob("*.yaml"))
    print(f"Found {len(yaml_files)} clang-tidy YAML files")
    
    if not yaml_files:
        print("No YAML files found!")
        return
    
    detailed_rows = []
    summary_rows = []
    
    for i, yaml_path in enumerate(yaml_files):
        if (i + 1) % 1000 == 0:
            print(f"Processing {i+1}/{len(yaml_files)}...")
        
        model, gen, batch, filename = extract_file_info(yaml_path)
        if not model:
            continue
        
        problem_key = extract_problem_key(filename)
        rel_file = f"{model}/{gen}/{batch}/{filename}"
        
        diagnostics = parse_yaml_file(yaml_path)
        
        # Aggregate by level and category
        level_counts = defaultdict(int)
        category_counts = defaultdict(int)
        diag_name_counts = defaultdict(int)
        
        for diag in diagnostics:
            level = diag["level"]
            name = diag["diagnostic_name"]
            category = categorize_diagnostic(name)
            
            level_counts[level] += 1
            category_counts[category] += 1
            diag_name_counts[name] += 1
            
            # Detailed row
            detailed_rows.append({
                "file": rel_file,
                "model": model,
                "gen": gen,
                "batch": batch,
                "problem_key": problem_key,
                "diagnostic_name": name,
                "category": category,
                "level": level,
                "message": diag["message"],
            })
        
        # Summary row
        summary_rows.append({
            "file": rel_file,
            "model": model,
            "gen": gen,
            "batch": batch,
            "problem_key": problem_key,
            "total_diagnostics": len(diagnostics),
            "warnings": level_counts.get("Warning", 0),
            "errors": level_counts.get("Error", 0),
            "notes": level_counts.get("Note", 0),
            # Categories
            "bugprone": category_counts.get("bugprone", 0),
            "performance": category_counts.get("performance", 0),
            "modernize": category_counts.get("modernize", 0),
            "readability": category_counts.get("readability", 0),
            "cppcoreguidelines": category_counts.get("cppcoreguidelines", 0),
            "cert": category_counts.get("cert", 0),
            "analyzer": category_counts.get("analyzer", 0),
            "compiler_warning": category_counts.get("compiler-warning", 0),
            "misc": category_counts.get("misc", 0),
            "hicpp": category_counts.get("hicpp", 0),
            "other": category_counts.get("other", 0),
        })
    
    # Write CSVs
    import csv
    
    # Detailed
    detailed_path = OUT_DIR / "clang_tidy_detailed.csv"
    if detailed_rows:
        with open(detailed_path, "w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=detailed_rows[0].keys())
            writer.writeheader()
            writer.writerows(detailed_rows)
        print(f"Wrote {len(detailed_rows)} rows → {detailed_path}")
    else:
        print("No detailed rows to write")
    
    # Summary
    summary_path = OUT_DIR / "clang_tidy_summary.csv"
    if summary_rows:
        with open(summary_path, "w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=summary_rows[0].keys())
            writer.writeheader()
            writer.writerows(summary_rows)
        print(f"Wrote {len(summary_rows)} rows → {summary_path}")
    else:
        print("No summary rows to write")
    
    # Print aggregate stats
    print("\n=== Aggregate Stats ===")
    total_diags = sum(r["total_diagnostics"] for r in summary_rows)
    total_bugprone = sum(r["bugprone"] for r in summary_rows)
    total_perf = sum(r["performance"] for r in summary_rows)
    total_analyzer = sum(r["analyzer"] for r in summary_rows)
    print(f"Total diagnostics: {total_diags}")
    print(f"Bugprone: {total_bugprone}")
    print(f"Performance: {total_perf}")
    print(f"Analyzer: {total_analyzer}")


if __name__ == "__main__":
    main()
