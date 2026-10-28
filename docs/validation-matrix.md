# Validation matrix

## Priority validation set

The first pass should target a small, stable set of firmware profiles:

- Retail PS Vita 3.60
- Retail PS Vita 3.65
- Retail PS Vita 3.73
- PSTV 3.74 (if available)

## Secondary validation set

After the first stable render path is validated:
- Retail PS Vita 3.61
- Retail PS Vita 3.68
- Devkit 3.70
- Testkit 3.72

## Validation checks

For each target firmware profile, validate:
- module identification succeeds
- shell text segment matches expected size
- patch injection is accepted
- stock fallback remains present
- LiveArea still loads after custom hook activation
- app list and folder rendering remain stable
- icon focus and selection behavior remains stable

## Pass criteria

A firmware profile passes only if:
- the module loads without crashing
- the LiveArea page renders without distorted or missing UI
- the plugin can disable cleanly
- the fallback path preserves stock appearance when the theme cannot apply

## Failure handling

Any failure in the above checks should immediately revert to stock UI and log the exact incompatibility point.
