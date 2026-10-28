# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design language, built as a separate research and development project.

## Goal

Create a PS5-inspired visual design layer for the PS Vita LiveArea while keeping the project technically separate from `livearea_nolimits`.

## Distinction from livearea_nolimits

`livearea_nolimits` is a shell-capacity patching project. It expands Vita LiveArea page and icon limits and manages caching behavior. It is not a UI theme project.

This repository is intentionally different:
- focus: visual design and UI composition
- implementation: custom resource pipeline + shell hook strategy
- compatibility target: Vita firmware-specific UI reverse engineering

## Current status

This repository is at a technical scaffold stage. It contains:
- a Vita plugin skeleton
- theme/runtime configuration stubs
- an asset-loading layer concept
- documentation for reverse-engineering and design direction

It is not yet a complete PS5-like theme implementation.

## Architecture

- `src/main.c` – module entry point
- `src/theme_patch.c` – shell patching and UI hook entry
- `src/theme_runtime.c` – runtime state and theme config
- `src/asset_loader.c` – asset loading and resource pipeline
- `include/theme_runtime.h` – runtime/public theme APIs
- `assets/` – theme resources and placeholders
- `docs/` – research notes and implementation roadmap

## Target plan

1. Confirm firmware-specific LiveArea shell structure
2. Map UI drawing points and resource references
3. Build a safe theme injection layer
4. Add PS5-inspired color/style definitions
5. Implement asset fallback and overlay system
6. Validate on supported Vita builds

## Firmware reference

The project will initially focus on Vita firmware families already validated by `livearea_nolimits`:

- Retail PS Vita / PSTV: 3.60–3.74
- Testkit: 3.60, 3.61, 3.63, 3.65, 3.67, 3.68, 3.70, 3.72, 3.73
- Devkit: 3.60, 3.61, 3.63, 3.65, 3.67, 3.68, 3.69, 3.70, 3.71, 3.73

## Important note

This project requires firmware-specific reverse engineering and should be treated as a research project until enough shell hooks and resource injection points are validated.
