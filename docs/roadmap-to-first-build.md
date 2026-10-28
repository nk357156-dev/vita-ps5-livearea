# Roadmap to first successful build

## Milestone 1 — project scaffold

Complete:
- repo setup
- module skeleton
- runtime config
- patch API stubs
- docs package

## Milestone 2 — compatibility layer

Required:
- firmware profile model
- module validation flow
- stock fallback path
- supported firmware mapping

## Milestone 3 — shell analysis

Required:
- identify LiveArea render path
- identify background and icon overlay data
- identify safe hook sites
- record differences between firmware variants

## Milestone 4 — minimal custom theme

Required:
- custom asset pack for backgrounds and overlays
- simple style selection engine
- test-only UI overrides
- fallback branch for unsupported profiles

## Milestone 5 — first stable build

Requirements:
- one known-good firmware profile
- no shell crash
- LiveArea remains stable during navigation
- fallback to stock UI remains available

## Milestone 6 — broader support

Only after milestone 5:
- add second firmware profile
- expand to additional hardware classes
- keep compatibility matrix updated

## Rule

No unsupported firmware profile should be treated as a target until the exact shell offset and patch path has been validated.
