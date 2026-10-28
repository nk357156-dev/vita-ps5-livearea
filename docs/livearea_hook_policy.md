# Hook policy for LiveArea safety review

## Goal

The project must not apply any LiveArea visual override until the candidate hook passes a strict policy gate. This follows the same fail-closed model described in the reference release:

- https://github.com/devnoname120/livearea_nolimits/releases/tag/v2.1.0

## Policy rules

A candidate hook is allowed only if all of the following are true:

- firmware has been checked
- risk is not high
- hook is reversible
- hook is isolated to a local render path
- hook is considered safe
- fallback remains active

If any condition fails, the hook must remain blocked.

## Policy states

- `HOOK_POLICY_BLOCKED` — unsafe or unverified
- `HOOK_POLICY_REVIEW` — candidate exists, needs validation
- `HOOK_POLICY_ALLOWED` — validated and safe to activate

## Initial candidate set

The first review candidates should be limited to local and isolated visual elements:

- selected_icon_glow
- text_color_application
- panel_background_frost
- icon_mask_alpha
- widget_glass_overlay
- local_list_item_theme

## Hard-blocked candidates

The following are explicitly blocked until proven safe:

- full_livearea_redraw
- global_page_lifecycle_patch
- global_layout_composition_patch
- any shell-wide state mutation
- any patch touching shared UI containers without a rollback path

## Evaluation logic

The policy should reject a hook when:

```c
if (policy->risk == 2)
    return -1;

if (!policy->firmware_checked)
    return -1;

if (!policy->reversible)
    return -1;

if (!policy->isolated)
    return -1;

if (!policy->safe)
    return -1;
```

## Safe activation model

Only after a candidate clears the policy gate may it enter the enabled stage.
A hook must still remain under fallback control at all times.

This policy exists to prevent unsafe direct modifications to Vita LiveArea state.
