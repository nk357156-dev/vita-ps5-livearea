# Hook candidate matrix for LiveArea safety review

## Goal

Before any real UI override is applied, each LiveArea render candidate must be reviewed against the fail-closed rules used in `livearea_nolimits` v2.1.0:

- firmware validated
- hook must be reversible
- hook must be isolated
- fallback must remain active
- high-risk paths remain blocked

## Candidate matrix

| Name | Category | Risk | Firmware checked | Reversible | Isolated | Safe | Verdict |
|------|----------|------|------------------|-----------|----------|------|---------|
| panel_background_redraw | background | low | no | no | no | no | blocked |
| selected_icon_glow | highlight | low | no | no | no | no | blocked |
| glass_overlay_layer | overlay | medium | no | no | no | no | blocked |
| icon_mask_alpha | icon rendering | medium | no | no | no | no | blocked |
| text_color_application | text | low | no | no | no | no | blocked |
| layout_spacing_override | layout | medium | no | no | no | no | blocked |
| full_livearea_redraw | shell layout | high | no | no | no | no | blocked |
| global_page_lifecycle_patch | shell lifecycle | high | no | no | no | no | blocked |

## Risk policy

### Low risk

Suitable for investigation only when all of the following are true:

- local widget / rendering path
- no global shell impact
- reversible in-place patch or override
- safe fallback available

Examples:
- selected item highlight overlay
- text color for a local element
- non-global background styling

### Medium risk

Requires deeper validation before activation:

- glass overlay effects
- icon mask / alpha pass
- layout-local spacing tweaks

Medium-risk hooks are not blocked automatically, but they require explicit firmware verification and full reversibility proof.

### High risk

Always blocked until proven safe.

Examples:
- full LiveArea redraw
- shell lifecycle patching
- global render object replacement
- anything modifying shared layout state across pages

## Required checks before any hook is allowed

1. firmware match validated
2. shell module compatible
3. hook isolated to a single component
4. stock UI can be restored without reset
5. no global visual state corruption
6. fallback path remains live

## Current status

This matrix is a review list, not an activation list. At the moment, no candidate is considered safe for actual patching.

This is the correct stage for the project: safe cataloging of possible hooks before real LiveArea modifications.
