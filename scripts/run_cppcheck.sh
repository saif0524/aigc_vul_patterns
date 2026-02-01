#!/bin/bash

ROOT="derived/cpp"
OUT="analysis/cppcheck"
mkdir -p "$OUT"

MODELS=("gemma" "llama" "qwen")
GENS=("gen_1" "gen_2" "gen_3")

for model in "${MODELS[@]}"; do
  for gen in "${GENS[@]}"; do
    SRC="$ROOT/$model/$gen"
    OUTDIR="$OUT/$model/$gen"
    mkdir -p "$OUTDIR"

    if [ -d "$SRC" ]; then
      find "$SRC" -name "*.cpp" | while read -r file; do
        base=$(basename "$file")
        outfile="$OUTDIR/${base}.xml"

        echo "cppcheck: $file"

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
    fi
  done
done
