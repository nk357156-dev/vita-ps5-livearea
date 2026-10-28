# Reverse-engineering checklist

## Objective

Confirm which shell and PAF drawing structures are responsible for the LiveArea visual composition before applying theme overrides.

## Checklist

### A. Module identification
- [ ] Confirm the base `SceShell` module is loaded
- [ ] Record module NID for each supported firmware
- [ ] Validate segment 0 text layout and size
- [ ] Check module identity differences between retail and dev/test builds

### B. LiveArea entry points
- [ ] Locate page and folder render flow
- [ ] Identify the function that builds icon placements
- [ ] Identify functions responsible for background composition
- [ ] Identify focus/selection rendering routines

### C. Rendering resource references
- [ ] Map image resources used by page panels
- [ ] Identify asset loading path for app icons and folder art
- [ ] Locate handle/resource IDs for overlay textures
- [ ] Confirm whether fonts or text style data are embedded or loaded dynamically

### D. Hook placement strategy
- [ ] Identify minimal override points for page background replacements
- [ ] Identify minimal override points for icon frame overlays
- [ ] Identify a safe place to add glow or focus ring rendering
- [ ] Ensure all hooks are reversible

### E. Safety validation
- [ ] Test with stock fallback enabled
- [ ] Confirm no crash on folder navigation
- [ ] Confirm no broken icon placement after app list updates
- [ ] Re-test on a second supported firmware build

## Minimal evidence required before visual patching

Before applying any live UI changes, the project should have:
- valid module NID and text segment verification
- at least one confirmed LiveArea render location
- one safe fallback branch
- one firmware-specific success case

## Completion rule

The visual patching task is not “done” until the theme has been tested without breaking page rendering, app listing, or app startup flow.
