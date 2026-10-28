# Selected icon glow validation report

## Candidate

`selected_icon_glow`

## Category

Selected item highlight / local widget accent layer

## Objective

Validate whether the candidate hook can be enabled under the safety-first LiveArea model described in the reference architecture:

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

The goal is not to patch the shell blindly. The goal is to prove that the candidate is:

- local to a widget or selected object
- reversible without reboot or shell reset
- isolated from global shell state
- safe under fallback policy

## Risk classification

- Risk: low
- Firmware dependence: local widget profile only
- Global shell impact: none expected
- Candidate status before validation: `REVIEW`

## Acceptance criteria

A candidate may move from `REVIEW` to `ALLOWED` only if all of the following are true:

- firmware_checked == 1
- risk != high
- reversible == 1
- isolated == 1
- safe == 1
- fallback_active == 1

If any value is false, the candidate must remain `BLOCKED`.

## Validation table

| Check | Result | Notes |
|-------|--------|-------|
| firmware profile match | pending | confirm active shell profile matches the selected highlight target |
| local render scope | pending | confirm it does not affect shared shell objects |
| reversibility | pending | save original state and validate restore path |
| isolation | pending | ensure no global page or layout state is touched |
| safety under fallback | pending | trigger fallback and confirm stock state returns |
| adjacent-item safety | pending | ensure no artifacts leak to neighboring entries |
| debug-only gate | pending | candidate must be disabled unless debug validation flag is explicitly enabled |

## Required test flow

### 1. Firmware validation

- load active firmware profile
- check whether the current shell build matches the expected local rendering path
- reject if the candidate depends on an unsupported build or a shared global object

### 2. Local-scope validation

- confirm the highlight is applied only to the selected item
- confirm no global render object is overwritten
- confirm no page lifecycle hook is required

### 3. Reversibility validation

- save original color, alpha, glow and highlight state
- implement restore routine
- verify restore works under fallback trigger without reboot

### 4. Fallback validation

- enable fallback mode during validation
- confirm the original stock highlight state returns
- confirm no ghost state remains in the selected icon or adjacent icon rows

### 5. Safety validation

- test under debug-only gate
- ensure adjacent items remain unaffected
- ensure no state leaks into shared shell elements

## Hard-blocked candidates

The following remain explicitly blocked and must not be used in this project until proven safe:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- shared_shell_state_mutation

These are disallowed because they change global or lifecycle-level shell state rather than a local widget highlight.

## Current verdict

`selected_icon_glow` is currently in `REVIEW` state, not `ALLOWED`.

It is the correct first candidate for review because it is isolated and local, but it still requires proof of:

- firmware compatibility
- local-scope integrity
- reversibility
- fallback restoration
- zero global artifact leakage

Until those checks pass, the candidate must remain under review and the project must stay fail-closed.
