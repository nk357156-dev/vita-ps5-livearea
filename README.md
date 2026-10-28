# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design language, built as a separate research and development project.

## Purpose

This repository is a dedicated experimental project for creating a PS5-inspired visual treatment for the PS Vita LiveArea. It is intentionally separated from `livearea_nolimits`, which is a shell-capacity patch plugin rather than a UI theme system.

## Why a separate project

`livearea_nolimits` solves a different problem:
- expands LiveArea page and icon capacity
- validates shell firmware profiles
- injects patch bytes into `SceShell`
- manages icon caching and recovery logic

This project solves a different problem:
- design and render a custom LiveArea presentation
- load PS5-like assets and overlays
- inject UI overrides in a safe, reversible way
- keep the implementation separate from raw live-area expansion logic

## Scope

This project is currently a technical scaffold and engineering blueprint for a custom Vita shell UI experiment. It includes:
- plugin architecture
- runtime theme state model
- reverse-engineering plan
- validation targets
- design language documentation

It is not a finished PS5-inspired built theme yet.

## Project architecture

- `src/main.c` – module entry point
- `src/theme_patch.c` – patching and shell hook integration
- `src/theme_runtime.c` – runtime theme state and configuration
- `src/asset_loader.c` – asset pipeline abstraction
- `include/theme_runtime.h` – runtime state API
- `include/theme_patch.h` – shell patch API
- `assets/` – custom resources and placeholders
- `docs/` – research, design and validation docs

## Design direction

The visual language is inspired by PS5 UI semantics:
- dark neutral base
- neon cyan / blue accents
- glass-like layered panels
- clean high-contrast text
- icon glow and focus treatment
- modern motion cues with subtle transitions

## Build status

This repository is intended to be built with VitaSDK and a Vita-compatible toolchain. It remains in a research and bootstrap stage until shell injection points are more deeply confirmed.

## Firmware reference

This project initially targets firmware families already used in `livearea_nolimits` research:

- Retail PS Vita / PSTV: 3.60–3.74
- Testkit: 3.60, 3.61, 3.63, 3.65, 3.67, 3.68, 3.70, 3.72, 3.73
- Devkit: 3.60, 3.61, 3.63, 3.65, 3.67, 3.68, 3.69, 3.70, 3.71, 3.73

## Roadmap

1. Confirm the exact `SceShell` draw paths for LiveArea pages and folders
2. Identify stable UI resource injection points
3. Add runtime theme state and theme style layer
4. Implement asset pipeline for backgrounds, overlays and focus states
5. Add minimal safe fallback mode for unsupported firmware
6. Validate on a narrow firmware subset before broadening support

## Important note

This is a firmware-specific project. Shell rendering behavior and module layouts vary across Vita builds, so a safe, reversible design is essential.
