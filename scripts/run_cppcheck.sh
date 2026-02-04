#!/bin/bash
# scripts/run_cppcheck.sh
set -euo pipefail

# Force args
if [ $# -ne 1 ]; then
  echo "Usage: $0 {demo|full}"
  exit 1
fi

MODE="$1"
if [[ "$MODE" != "demo" && "$MODE" != "full" ]]; then
  echo "Usage: $0 {demo|full}"
  exit 1
fi

# Mode-specific roots
if [ "$MODE" = "demo" ]; then
  CPP_ROOT="demo/demo_derived/demo_cpp"
  OUT="demo/demo_analysis/demo_cppcheck"
else
  CPP_ROOT="derived/cpp"
  OUT="analysis/cppcheck"
fi

mkdir -p "$OUT"

# LLM runs
LLM_MODELS=("gemma" "llama" "qwen")
LLM_GENS=("gen_1" "gen_2" "gen_3")

# Human runs
HUMAN_MODEL="human"
HUMAN_GENS=("soln1" "soln2")

run_dir () {
  local model="$1"
  local gen="$2"
  local SRC="$CPP_ROOT/$model/$gen"

  [ -d "$SRC" ] || return 0

  find "$SRC" -name "*.cpp" -print0 | while IFS= read -r -d '' file; do
    rel="${file#$SRC/}"                 # preserves batch subdirs if present
    outdir="$OUT/$model/$gen/$(dirname "$rel")"
    mkdir -p "$outdir"

    base="$(basename "$file")"
    outfile="$outdir/${base}.xml"

    echo "cppcheck: $file -> $outfile"

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
}

# Run LLMs
for model in "${LLM_MODELS[@]}"; do
  for gen in "${LLM_GENS[@]}"; do
    run_dir "$model" "$gen"
  done
done

# Run human
for gen in "${HUMAN_GENS[@]}"; do
  run_dir "$HUMAN_MODEL" "$gen"
done

echo "Done. Outputs in: $OUT"
