# Candidate Validation Report for Vita LiveArea

## Objective

This document is the first serious validation pass for LiveArea custom override candidates. It follows the fail-closed architecture described in the reference release:

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

The goal is not to patch the shell blindly. The goal is to verify that a candidate hook is:

- compatible with the current firmware profile
- isolated to a local visual layer
- reversible without a reboot or manual shell cleanup
- safe under fallback policy

## Validation model

A candidate is allowed only if all of the following are true:

- firmware_checked == 1
- risk != high
- reversible == 1
- isolated == 1
- safe == 1
- fallback_active == 1

Any missing condition automatically marks the candidate as `BLOCKED`.

## Candidate table

| Candidate | Category | Risk | Firmware scope | Reversible | Isolated | Verdict |
|-----------|----------|------|----------------|-----------|----------|---------|
| selected_icon_glow | selected item highlight | low | local widget | yes | yes | REVIEW |
| text_color_application | text rendering | low | local widget | yes | yes | REVIEW |
| panel_background_frost | background layer | medium | local panel | yes | yes | REVIEW |
| icon_mask_alpha | icon rendering | medium | local icon object | yes | yes | REVIEW |
| widget_glass_overlay | overlay | medium | local widget | likely | yes | REVIEW |
| full_livearea_redraw | shell layout | high | global | no | no | BLOCKED |
| global_page_lifecycle_patch | shell lifecycle | high | global | no | no | BLOCKED |
| global_layout_composition_patch | layout system | high | global | no | no | BLOCKED |
| shared_shell_state_mutation | shell state | high | global | no | no | BLOCKED |

## First candidate selection

The first real candidate selected for validation is:

- `selected_icon_glow`

Reason:
- visual scope is local to the selected item
- it does not require shell-wide state mutation
- it is likely reversible using cached original colors or a direct restore pass
- the fallback path can restore standard selection colors without resetting the shell

## Validation checklist for first candidate

### 1. Firmware validation
- confirm active firmware profile matches the candidate profile
- reject if incompatible firmware or unsupported shell build
- verify no global shell assumptions are made

### 2. Isolation validation
- confirm the candidate affects only selected item highlight state
- confirm no shared global render object is overwritten
- confirm no page lifecycle hook is required

### 3. Reversibility validation
- save the original selector color and alpha state
- implement restore path that resets to original values
- validate restore path under fallback trigger

### 4. Fallback validation
- trigger fallback during test
- verify stock selection highlight returns immediately
- verify no ghost state remains in the shell

### 5. Safety validation
- test with debug-only toggle enabled
- reject if any artifact leaks into adjacent items
- reject if renderer state is not isolated

## Hard blockers

The following candidates remain blocked until proven safe:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- any patch modifying shared shell globals

These are considered unsafe because they change the system-level layout or runtime state beyond a single widget or visual layer.

## Decision gate

A candidate can move from `REVIEW` to `ALLOWED` only when all checks pass:

1. firmware profile check passed
2. visual scope confirmed local
3. restore path implemented and tested
4. fallback restored stock state
5. no global shell artifacts observed

Without this evidence, the candidate remains in `REVIEW` or `BLOCKED` state.

## Current project result

At this point the project has a real validation pipeline and a concrete first candidate for testing, not just a generic architecture document.

This is the first serious milestone because we have:

- a risk-ordered candidate set
- a selected first candidate
- explicit safety criteria
- a fallback-first validation model

The project is still intentionally conservative and safe. That is the correct engineering posture for Vita LiveArea modification.
