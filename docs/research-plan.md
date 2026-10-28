# Reverse-engineering and implementation plan

## 1. Starting point

The existing `livearea_nolimits` project is a good baseline for understanding how Vita shell patching works:
- it validates shell module identity
- it finds the correct text segment
- it applies firmware-specific patches using `taiInjectData`
- it maintains compatibility profiles for multiple firmware versions

This project should reuse that overall structure, but target visual rendering instead of count limits.

## 2. What to reverse-engineer

We need to identify the shell elements used to render LiveArea pages:
- page background
- icon container layout
- page text labels
- focus/highlight overlays
- folder view composition
- scrolling behavior and transitions

In practice, this means tracing:
- `SceShell` memory layout
- PAF UI widgets used by LiveArea
- icon image loading and caching
- the functions that compose page elements and overlays

## 3. Likely technical path

### Phase A — baseline hook discovery
- locate `SceShell` module
- identify livearea text segment and module NID
- verify firmware profile and offsets
- establish a minimal patch injection framework

### Phase B — UI drawing points
- locate page composition functions
- capture or disassemble rendering calls
- identify background and icon overlay structures
- identify text and hitbox resources

### Phase C — custom style layer
- replace or override color data for UI surfaces
- swap background textures or overlays
- adjust highlight/focus state rendering
- build asset fallback strategy for unsupported firmware

### Phase D — runtime safety
- ensure patching remains reversible
- avoid breaking icon and page update logic
- maintain fallback to stock UI on unsupported module layouts

## 4. Asset strategy

Use a layered asset model:
- base background textures
- accent overlays
- icon masks
- focus glow textures
- custom fonts or text style data

The asset system should support:
- default stock fallback
- custom PS5-like packs
- per-firmware compatibility profiles

## 5. Validation workflow

1. Validate module identification and shell text structure
2. Confirm page drawing hooks before injecting any visual override
3. Test with minimal theme change on a single firmware
4. Expand to a wider firmware set only once the UI hooks are stable

## 6. Risk assessment

This is a high-risk project because:
- the Vita shell is firmware-specific
- shell UI composition is tightly coupled to memory layout
- improper patching can break LiveArea boot or rendering

The safest approach is to start with a single, well-understood firmware profile and keep all other builds as fallback-only targets.
