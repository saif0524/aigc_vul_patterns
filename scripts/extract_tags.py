# scripts/extract_problem_tags.py
import json, glob, csv, os

rows = []

for jf in sorted(glob.glob("data/problem_tags/problem_tags_*.json")):
    shard_file = os.path.basename(jf).split("_")[-1].replace(".json", "")
    data = json.load(open(jf))

    for entry in data:
        shard = str(entry.get("shard", shard_file))
        problem_key = entry["problem_name"]           # e.g., "1012_E. Cycle sort"
        tags = entry.get("cf_tags", [])

        rows.append({
            "problem_key": problem_key,
            "shard": shard,
            "tags": "|".join(tags)
        })

out_path = "results/raw_csv/problem_tags.csv"
os.makedirs(os.path.dirname(out_path), exist_ok=True)

with open(out_path, "w", newline="") as f:
    writer = csv.DictWriter(f, fieldnames=["problem_key", "shard", "tags"])
    writer.writeheader()
    writer.writerows(rows)

print(f"Saved {out_path} with {len(rows)} rows")
