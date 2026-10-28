# Firmware and validation targets

## Initial target

This project will begin with the firmware families referenced by `livearea_nolimits` because they already have validated shell patching patterns.

### Retail PS Vita / PSTV
- 3.60
- 3.61
- 3.63
- 3.65
- 3.67
- 3.68
- 3.69
- 3.70
- 3.71
- 3.72
- 3.73
- 3.74

### Testkit
- 3.60
- 3.61
- 3.63
- 3.65
- 3.67
- 3.68
- 3.70
- 3.72
- 3.73

### Devkit
- 3.60
- 3.61
- 3.63
- 3.65
- 3.67
- 3.68
- 3.69
- 3.70
- 3.71
- 3.73

## Recommended initial validation subset

For a first pass, we should validate a minimal set:
- retail 3.60
- retail 3.65
- retail 3.73
- PSTV 3.74 (if available)

This creates a stable baseline while the UI patching layer is still experimental.

## Validation rules

- keep a clean stock fallback
- verify the shell module loads before theme hook activation
- confirm page rendering remains stable after patch injection
- test asset fallback when a custom resource is unavailable
- keep all unsupported firmware profiles in fallback mode
