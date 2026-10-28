# Project charter

## Project name

`vita-ps5-livearea`

## Objective

Design and prototype a PS5-inspired LiveArea theme for the PlayStation Vita while maintaining a safe, firmware-aware, and reversible implementation path.

## Non-objectives

This project does not aim to:
- fork or replace `livearea_nolimits` functionality
- turn the Vita into a PS5 shell
- assume all firmware builds are compatible without validation
- ship a theme without a fallback strategy

## Success criteria

The project is successful when:
- the custom theme can be enabled safely on at least one supported firmware profile
- the system can revert to stock LiveArea when a profile is unsupported
- the UI remains stable during navigation, folder access, and icon focus
- the design matches the intended PS5-inspired design language without breaking shell behavior

## Risk factors

- firmware-specific offsets
- unknown UI rendering entry points
- shell layout differences across Vita revisions
- asset pipeline limitations
- broken rendering or boot issues if patches are incorrect

## Constraints

- must keep a fallback path to stock LiveArea
- must avoid irreversible shell modifications
- must respect VitaSDK build workflow and module rules
- must be validated on a narrow, known set of firmware profiles first

## Ownership

This project is an engineering research project with explicit emphasis on safe experimentation and compatibility validation.
