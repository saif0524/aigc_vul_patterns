import json, glob, csv

has_tests = no_tests = 0

for jf in glob.glob("data/testcases/testcases-train-*.json"):
    data = json.load(open(jf))
    for inst in data:
        pub = len(inst["public_tests"]["input"])
        priv = len(inst["private_tests"]["input"])
        if pub + priv > 0:
            has_tests += 1
        else:
            no_tests += 1

with open("results/tables/testcase_coverage.csv", "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["total_instructions","with_tests","without_tests"])
    writer.writerow([has_tests + no_tests, has_tests, no_tests])

print("Saved results/tables/testcase_coverage.csv")
