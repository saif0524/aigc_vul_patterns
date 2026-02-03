#!/usr/bin/env bash
set -euo pipefail

# -----------------------------
# Argument parsing
# -----------------------------
MODE=""

usage() {
  echo "Usage: $0 --mode {demo|full}"
  exit 1
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --mode)
      MODE="$2"
      shift 2
      ;;
    -h|--help)
      usage
      ;;
    *)
      echo "Unknown argument: $1"
      usage
      ;;
  esac
done

if [[ -z "$MODE" ]]; then
  echo "ERROR: --mode is required"
  usage
fi

if [[ "$MODE" != "demo" && "$MODE" != "full" ]]; then
  echo "ERROR: --mode must be one of {demo, full}"
  usage
fi

# -----------------------------
# Resolve paths
# -----------------------------
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"

if [[ "$MODE" == "demo" ]]; then
  SRC_ROOT="$REPO_ROOT/demo/demo_derived/demo_cpp"
  OUT_ROOT="$REPO_ROOT/demo/demo_analysis/demo_clang_tidy"
  TARGETS=(gemma llama qwen human)
else
  SRC_ROOT="$REPO_ROOT/derived/cpp"
  OUT_ROOT="$REPO_ROOT/analysis/clang_tidy"
  TARGETS=(gemma llama qwen)
fi

# -----------------------------
# Sanity checks
# -----------------------------
for t in "${TARGETS[@]}"; do
  if [[ ! -d "$SRC_ROOT/$t" ]]; then
    echo "ERROR: Missing directory $SRC_ROOT/$t" >&2
    exit 1
  fi
done

echo "Running clang-tidy"
echo "Mode:    $MODE"
echo "Source:  $SRC_ROOT"
echo "Output:  $OUT_ROOT"
echo

# -----------------------------
# Run clang-tidy
# -----------------------------
for model in "${TARGETS[@]}"; do
  find "$SRC_ROOT/$model" -type f -name "*.cpp"
done | \
xargs -P 4 -n 1 bash -c '
  src="$0"

  rel="${src#'"$SRC_ROOT"'/}"
  out_dir="'"$OUT_ROOT"'/${rel%/*}"

  mkdir -p "$out_dir"

  clang-tidy-21 "$src" \
    -p=. \
    -checks="clang-analyzer-security*,bugprone-*,performance-*,modernize-*" \
    -export-fixes="$out_dir/$(basename "${src%.cpp}").yaml" \
    -- -std=c++17
'