#!/bin/bash

ROOT="derived/cpp/human"
OUT="analysis/cppcheck/human"

mkdir -p "$OUT"

# iterate over soln1 / soln2
for soln in "$ROOT"/*; do
  [ -d "$soln" ] || continue

  soln_id=$(basename "$soln")
  echo "[*] Processing human $soln_id"

  # iterate over batches like 00000, 00001, ...
  for batch in "$soln"/*; do
    [ -d "$batch" ] || continue

    batch_id=$(basename "$batch")
    OUTDIR="$OUT/$soln_id/$batch_id"
    mkdir -p "$OUTDIR"

    echo "  └─ batch $batch_id"

    find "$batch" -name "*.cpp" | while read -r file; do
      base=$(basename "$file")
      outfile="$OUTDIR/${base}.xml"

      echo "    cppcheck: $file"

      if ! timeout 30s cppcheck \
        --enable=warning,style,performance,portability \
        --inconclusive \
        --std=c++17 \
        --inline-suppr \
        --xml \
        "$file" 2> "$outfile"; then
        echo "$file" >> "$OUT/timeouts.log"
      fi
    done
  done
done