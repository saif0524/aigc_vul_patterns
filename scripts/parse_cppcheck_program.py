import xml.etree.ElementTree as ET
import csv, glob, os

INPUT_GLOB = "analysis/cppcheck/**/*.xml"
OUTPUT_CSV = "results/raw_csv/cppcheck_program_level.csv"

rows = []

for xml_file in glob.glob(INPUT_GLOB, recursive=True):
    parts = xml_file.split(os.sep)
    try:
        cpp_idx = parts.index("cppcheck")
        model = parts[cpp_idx + 1]
        generation = parts[cpp_idx + 2]
        batch = parts[cpp_idx + 3]
    except (ValueError, IndexError):
        continue

    filename = os.path.basename(xml_file)
    instruction_id = filename.replace(".cpp.xml", "").replace(".xml", "")

    try:
        tree = ET.parse(xml_file)
        errors = tree.findall(".//error")
    except ET.ParseError:
        continue

    cwes = set()
    for err in errors:
        if err.get("cwe"):
            cwes.add(err.get("cwe"))

    rows.append({
        "model": model,
        "generation": generation,
        "batch": batch,
        "instruction_id": instruction_id,
        "analyzed": 1,
        "has_cwe": int(len(cwes) > 0),
        "num_cwe_types": len(cwes),
        "cwe_list": "|".join(sorted(cwes))
    })

os.makedirs(os.path.dirname(OUTPUT_CSV), exist_ok=True)

with open(OUTPUT_CSV, "w", newline="") as f:
    writer = csv.DictWriter(
        f,
        fieldnames=[
            "model","generation","batch","instruction_id",
            "analyzed","has_cwe","num_cwe_types","cwe_list"
        ]
    )
    writer.writeheader()
    writer.writerows(rows)

print(f"Wrote {len(rows)} program-level rows")