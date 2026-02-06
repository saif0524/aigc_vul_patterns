# scripts/parse_cppcheck_unified.py
"""
Unified cppcheck analysis parser (DROP-IN, FIXED).

Fixes:
- Supports BOTH cppcheck layouts:
    A) analysis/cppcheck/<model>/<gen>/<file>.xml              (no batch folder)
    B) analysis/cppcheck/<model>/<gen>/<batch>/<file>.xml      (has batch folder)
- Keeps batch (defaults to "00000" when missing)
- Extracts problem_key from XML filename (stable across tools)
- Emits a summary row even if XML is empty/truncated (0 errors)

Outputs:
1) results/raw_csv/cppcheck_detailed.csv
2) results/raw_csv/cppcheck_summary.csv
"""

import xml.etree.ElementTree as ET
import csv
import glob
import os

INPUT_GLOB = "analysis/cppcheck/**/*.xml"
OUT_DIR = "results/raw_csv"


def normalize_problem_key(s: str) -> str:
    """Normalize problem_key to match tests/tags normalization."""
    if s is None:
        return ""
    s = str(s).strip().lower()
    s = s.replace(".cpp", "")
    for ch in ("'", "(", ")", "!", ",", ":", ";", "\""):
        s = s.replace(ch, "")
    s = s.replace("_", " ")
    s = s.replace(".", " ")
    s = s.replace("-", " ")
    s = " ".join(s.split())
    return s


def extract_problem_key_from_xml_filename(filename: str) -> str:
    """
    Example filenames:
      0000_1012_E._Cycle_sort.cpp.xml
      0000_152_E._Garden.cpp.xml

    We want problem_key:
      1012_E._Cycle_sort
      152_E._Garden

    Rule: strip .xml, then strip optional .cpp,
          then drop leading shard prefix up to first underscore.
    """
    base = filename
    if base.endswith(".xml"):
        base = base[:-4]
    if base.endswith(".cpp"):
        base = base[:-4]
    if "_" in base:
        base = base.split("_", 1)[1]
    return base


def extract_sample_id(model: str, generation: str, batch: str, filename: str) -> str:
    """
    Keep filename stem WITHOUT trailing .xml, but keep .cpp if present.
    """
    stem = filename[:-4] if filename.endswith(".xml") else filename
    return f"{model}/{generation}/{batch}/{stem}"


def parse_cppcheck_files():
    detailed_rows = []
    summary_rows = []

    for xml_file in glob.glob(INPUT_GLOB, recursive=True):
        parts = xml_file.split(os.sep)

        try:
            cpp_idx = parts.index("cppcheck")
            model = parts[cpp_idx + 1]
            generation = parts[cpp_idx + 2]

            # Next part may be batch OR filename (flat layout)
            next_part = parts[cpp_idx + 3]
            if next_part.endswith(".xml"):
                batch = "00000"
                filename = next_part
            else:
                batch = next_part
                filename = parts[cpp_idx + 4]
        except (ValueError, IndexError):
            continue

        problem_key = normalize_problem_key(
            extract_problem_key_from_xml_filename(filename)
        )
        sample_id = extract_sample_id(model, generation, batch, filename)

        errors = []
        parsed_ok = True
        try:
            tree = ET.parse(xml_file)
            errors = tree.findall(".//error")
        except ET.ParseError:
            # cppcheck sometimes emits empty/truncated XML
            parsed_ok = False
            errors = []

        # Detailed rows
        for err in errors:
            detailed_rows.append({
                "sample_id": sample_id,
                "model": model,
                "generation": generation,
                "batch": batch,
                "problem_key": problem_key,
                "error_id": err.get("id"),
                "severity": err.get("severity"),
                "cwe": err.get("cwe"),
                "message": err.get("msg"),
            })

        # Summary row
        cwes = set()
        severities = {}
        for err in errors:
            cwe = err.get("cwe")
            if cwe:
                cwes.add(str(cwe))
            sev = err.get("severity", "unknown")
            severities[sev] = severities.get(sev, 0) + 1

        summary_rows.append({
            "sample_id": sample_id,
            "model": model,
            "generation": generation,
            "batch": batch,
            "problem_key": problem_key,
            "analyzed": 1,
            "parsed_ok": int(parsed_ok),
            "total_errors": len(errors),
            "has_cwe": int(len(cwes) > 0),
            "num_cwe_types": len(cwes),
            "cwe_list": "|".join(sorted(cwes)),
            "error_count": severities.get("error", 0),
            "warning_count": severities.get("warning", 0),
            "style_count": severities.get("style", 0),
            "performance_count": severities.get("performance", 0),
            "portability_count": severities.get("portability", 0),
        })

    return detailed_rows, summary_rows


def write_outputs(detailed_rows, summary_rows):
    os.makedirs(OUT_DIR, exist_ok=True)

    detailed_csv = os.path.join(OUT_DIR, "cppcheck_detailed.csv")
    if detailed_rows:
        with open(detailed_csv, "w", newline="", encoding="utf-8") as f:
            writer = csv.DictWriter(
                f,
                fieldnames=[
                    "sample_id", "model", "generation", "batch", "problem_key",
                    "error_id", "severity", "cwe", "message"
                ],
            )
            writer.writeheader()
            writer.writerows(detailed_rows)
        print(f"Wrote {len(detailed_rows)} detailed rows → {detailed_csv}")
    else:
        print("No detailed errors found (detailed CSV not written).")

    summary_csv = os.path.join(OUT_DIR, "cppcheck_summary.csv")
    if summary_rows:
        with open(summary_csv, "w", newline="", encoding="utf-8") as f:
            writer = csv.DictWriter(
                f,
                fieldnames=[
                    "sample_id", "model", "generation", "batch", "problem_key",
                    "analyzed", "parsed_ok", "total_errors", "has_cwe", "num_cwe_types", "cwe_list",
                    "error_count", "warning_count", "style_count", "performance_count", "portability_count"
                ],
            )
            writer.writeheader()
            writer.writerows(summary_rows)
        print(f"Wrote {len(summary_rows)} summary rows → {summary_csv}")
    else:
        print("No programs analyzed (summary CSV not written).")


if __name__ == "__main__":
    detailed, summary = parse_cppcheck_files()
    write_outputs(detailed, summary)
