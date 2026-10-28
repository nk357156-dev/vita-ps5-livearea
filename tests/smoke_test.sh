#!/usr/bin/env bash
set -eu

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

required=(
  "$ROOT_DIR/src/main.c"
  "$ROOT_DIR/src/theme_patch.c"
  "$ROOT_DIR/src/asset_loader.c"
  "$ROOT_DIR/include/theme.h"
  "$ROOT_DIR/include/asset_loader.h"
  "$ROOT_DIR/vita_ps5_livearea.yml"
)

for path in "${required[@]}"; do
  if [[ ! -f "$path" ]]; then
    echo "Missing required file: $path" >&2
    exit 1
  fi
done

echo "Smoke test passed: project scaffold is present."
