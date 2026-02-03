import json, glob, csv

rows = []

for jf in glob.glob("data/problem_tags/problem_tags_*.json"):
    shard = jf.split("_")[-1].replace(".json","")
    data = json.load(open(jf))

    for idx, entry in enumerate(data):
        rows.append({
            "instruction_id": idx,
            "shard": shard,
            "tags": "|".join(entry["cf_tags"])
        })

with open("results/raw_csv/instruction_tags.csv", "w", newline="") as f:
    writer = csv.DictWriter(
        f,
        fieldnames=["instruction_id","shard","tags"]
    )
    writer.writeheader()
    writer.writerows(rows)

print("Saved results/raw_csv/instruction_tags.csv")