# Project structure

This project intentionally starts as a clean plugin scaffold, separate from the existing `livearea_nolimits` plugin.

## Directories

- `src/` — core source code
- `include/` — public headers
- `assets/` — UI resources and placeholders
- `docs/` — notes and plans
- `tests/` — validation scripts and smoke tests

## Key sources

- `src/main.c` — module entry points
- `src/theme_patch.c` — shell patching logic and theme hooks
- `src/asset_loader.c` — asset and resource loading
- `src/patch_bytes.S` — patch injection helpers
