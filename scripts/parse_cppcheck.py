import xml.etree.ElementTree as ET
import csv, glob, os, sys

INPUT_GLOB = "analysis/cppcheck/**/*.xml"
OUTPUT_CSV = "results/raw_csv/cppcheck_agg.csv"

rows = []

for xml_file in glob.glob(INPUT_GLOB, recursive=True):
    # Expected path:
    # analysis/cppcheck/<model>/<gen_x>/<file>.xml
    parts = xml_file.split(os.sep)

    try:
        cpp_idx = parts.index("cppcheck")
        model = parts[cpp_idx + 1]
        generation = parts[cpp_idx + 2]   # gen_1 / gen_2 / gen_3
    except (ValueError, IndexError):
        continue

    try:
        tree = ET.parse(xml_file)
    except ET.ParseError:
        continue  # empty or corrupt XML

    for err in tree.findall(".//error"):
        rows.append({
            "model": model,
            "generation": generation,
            "instruction_id": os.path.basename(xml_file).split("_")[0],
            "error_id": err.get("id"),
            "severity": err.get("severity"),
            "cwe": err.get("cwe"),
        })

# Ensure output directory exists
os.makedirs(os.path.dirname(OUTPUT_CSV), exist_ok=True)

if not rows:
    print("No cppcheck warnings found.")
    sys.exit(0)

with open(OUTPUT_CSV, "w", newline="") as f:
    writer = csv.DictWriter(
        f,
        fieldnames=["model", "generation", "instruction_id", "error_id", "severity", "cwe"]
    )
    writer.writeheader()
    writer.writerows(rows)

print(f"Wrote {len(rows)} rows to {OUTPUT_CSV}")
