# Architecture and runtime model

## Goals

The runtime architecture must separate:
- firmware compatibility logic
- theme state and UI style
- asset loading
- shell patch management
- fallback behavior

## Core components

### 1. Compatibility manager

Responsibilities:
- determine the active firmware profile
- recognize module IDs and text segment sizes
- verify that patch locations are valid
- reject unsupported builds cleanly

### 2. Theme runtime

Responsibilities:
- hold current theme state
- define active style: default, neon, glass
- hold toggles for dynamic background, custom icons, focus ring, etc.
- expose runtime values to render code

### 3. Asset loader

Responsibilities:
- load custom backgrounds, overlays, masks, and texture metadata
- validate required assets before activation
- fall back to stock resources when missing

### 4. Shell patch manager

Responsibilities:
- validate a patch target before injection
- keep patch injection reversible
- release patches on shutdown or failure
- provide a minimal fail-safe path to stock UI

### 5. Theme render layer

Responsibilities:
- compose the custom UI on top of LiveArea
- apply PS5-inspired colors and backgrounds
- adapt to focus state and icon selection
- leave the underlying shell layout intact unless a safe hook is confirmed

## Lifecycle

1. Module start
2. Runtime initialization with default safe settings
3. Firmware profile detection
4. Asset pack validation
5. Patch verification and hook activation
6. LiveArea custom theme active
7. Module stop releases all theme resources and hooks

## Safety rules

- if compatibility is unproven, default to stock UI
- patch only after validation succeeds
- never assume one firmware profile works for all builds
- keep fallback code active at all times
- log incompatibility and disable theme cleanly
