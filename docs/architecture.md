# Architecture overview

## Goal

Define a clean runtime and patching architecture for a PS5-inspired LiveArea UI project. The goal is to keep the code modular, firmware-aware, and safe to disable when unsupported.

## Core architectural principles

### 1. Separate UI design from shell patching

The project should separate:
- theme state and runtime configuration
- patch injection logic
- asset resource loading
- firmware compatibility checks

This keeps the shell work from becoming a monolithic code path.

### 2. Safe fallback by default

If the shell module layout differs from the expected profile, the plugin must fail gracefully and leave the system on stock LiveArea. The design should prefer stability over aggressive patching.

### 3. Firmware profile selection

The project should support a profile system similar to `livearea_nolimits`:
- module NID identification
- text size validation
- offset validation
- patch compatibility check
- rollback on mismatch

### 4. Theme layers

The visual system should be split into clear layers:

- base background layer
- panel / glass layer
- icon state layer
- focus / hover layer
- accent / glow layer
- text layer

This makes it easier to create a PS5-inspired look without hard-coding everything into a single patch.

## Layered runtime model

### Theme runtime
Responsible for:
- active style selection
- enabled/disabled state
- neon/glass toggle
- dynamic background mode
- icon recoloring settings
- UI scale and focus behavior

### Asset loader
Responsible for:
- loading custom texture packs
- loading UI colors and style metadata
- validating asset presence
- falling back to stock resources when missing

### Patch manager
Responsible for:
- locating target module and segment
- validating patches before injection
- applying visual hooks
- releasing patches on shutdown

### Compatibility manager
Responsible for:
- mapping target firmware profile
- checking module signatures and segment layout
- selecting supported style variants
- disabling custom rendering on unsupported profiles

## Lifecycle

1. Module loads
2. Theme runtime initializes to safe defaults
3. Compatibility manager resolves firmware profile
4. Asset loader loads custom pack if valid
5. Patch manager verifies and injects rendering hooks
6. LiveArea continues with theme overlay active
7. Module stop releases overrides and goes back to stock rendering

## Recommended file structure

- `src/main.c` – module entry
- `src/theme_runtime.c` – runtime state
- `src/theme_patch.c` – patch logic
- `src/asset_loader.c` – asset pipeline
- `src/compat.c` – firmware validation layer
- `include/theme_runtime.h` – runtime API
- `include/theme_patch.h` – patch API
- `include/compat.h` – compatibility API

## Runtime safety rules

- never patch before checking module identity
- never inject if the segment size differs from expected
- support a stock-fallback branch for every patch stage
- keep unload cleanup explicit and deterministic
- log incompatibility with a clear fail-safe mode

## Final principle

The project should behave like a visual skin layer, not a low-level shell rewrite. If compatibility cannot be proven, it should gracefully revert to the stock Vita interface.
