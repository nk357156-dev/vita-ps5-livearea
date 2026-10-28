# vita-ps5-livearea

PS Vita LiveArea UI project inspired by PS5 design language. This is a research-oriented, firmware-aware plugin project built as a separate initiative from `livearea_nolimits`.

## Reference source

This project uses the `livearea_nolimits` release as a technical baseline for Vita shell patching and firmware validation patterns:

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

## Goal

Create a PS5-inspired design layer for the PS Vita LiveArea while preserving system stability, enabling safe fallback, and keeping the project firmware-aware.

## Scope

This repository is a full project package for the design and engineering of a custom Vita LiveArea theme. It contains:
- project charter and engineering scope
- runtime architecture
- shell patching API
- design specification
- reverse-engineering checklist
- compatibility profile model
- validation matrix
- asset specification
- build and test playbook

## Distinction from livearea_nolimits

`livearea_nolimits` solves shell-capacity expansion and icon caching. This project is intentionally different:
- not a capacity patch project
- not a general-purpose shell rewrite
- focused on visual styling and theme injection
- designed around firmware-specific hook validation and safe fallback

## Repository structure

- `src/` – runtime and patching implementation stubs
- `include/` – public headers and module interfaces
- `docs/` – engineering and design package
- `assets/` – resource directories and placeholders
- `tests/` – validation and smoke test scripts
- `CMakeLists.txt` – Vita build system
- `vita_ps5_livearea.yml` – module metadata

## Current status

The repo is at the project-package stage: architecture, safety rules, design system, validation matrix, and reverse-engineering plan are documented and scaffolded. It is not yet a production UI theme.

## High-level roadmap

1. Confirm shell rendering points in `SceShell`
2. Define safe hook and fallback strategy
3. Add runtime theme state and compatibility logic
4. Build asset pipeline and PS5-inspired design system
5. Validate on a narrow firmware subset
6. Expand only after stable behavior is proven

## Important note

Because LiveArea rendering is firmware-specific, all theme work must be reversible and safely fallback to stock UI when compatibility cannot be confirmed.
