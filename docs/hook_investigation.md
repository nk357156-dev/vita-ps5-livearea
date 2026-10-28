# Safe LiveArea Hook Investigation Protocol

## Overview

This project follows the fail-closed model used in `livearea_nolimits` v2.1.0:

- validate firmware compatibility first
- validate theme profile second
- validate asset metadata third
- activate custom UI only after all checks pass
- immediately switch to stock LiveArea if any validation fails

This is a safety-first design. We do not patch LiveArea directly until the hook is validated and proven reversible.

## Core safety rules

1. Never patch LiveArea before compatibility validation succeeds.
2. Never assume a firmware profile is valid without module NID and shell checks.
3. Never enable custom theme if JSON profile or metadata are invalid.
4. Never keep custom rendering active if a patch cannot be safely reverted.
5. If any check fails, fallback to default stock LiveArea immediately.

## Investigation stages

### Stage 1: identify candidate render points

Potential safe candidate points include:

- panel backgrounds
- selected item highlight
- widget glass overlays
- icon mask rendering
- background layer compositing
- text color application
- layout spacing / margins

### Stage 2: classify candidate by risk

Each render point must be classified as one of:

- low risk: isolated visual layer, no global state changes
- medium risk: affects layout but remains local to one widget
- high risk: global shell state, page lifecycle, memory layout changes

Only low-risk or medium-risk locations may be considered for custom override.
High-risk points remain off-limits until further validation.

### Stage 3: validate reversibility

For every candidate point we must confirm:

- original bytes or state can be restored
- override is isolated to the target object
- fallback can restore stock UI without restart
- disabling the override does not corrupt the rest of the shell

### Stage 4: validate firmware assumptions

Before patching, confirm:

- supported firmware profile
- matching shell module build
- compatible memory layout assumptions
- no unsupported SceShell variant

### Stage 5: apply protected override only after the guard passes

Only after all validation passes should a hook be activated.

Pseudo-flow:

```c
if (!firmware_profile_supported()) {
    fallback_to_stock_livearea();
    return;
}

if (!theme_runtime_valid()) {
    fallback_to_stock_livearea();
    return;
}

if (!hook_is_safe()) {
    fallback_to_stock_livearea();
    return;
}

apply_safe_override();
```

## Fallback policy

Fallback is mandatory.

When a hook fails validation, the project must:

- disable the active custom theme
- restore stock LiveArea
- keep the shell stable
- log the failure reason

Fallback is not optional. The project is intentionally designed to fail closed.

## Logging requirements

Every stage of validation should log:

- selected firmware profile
- selected theme profile
- metadata validation result
- hook validation result
- fallback trigger reason

## Current project status

The project currently has the runtime-safe bootstrap layer and profile validation logic in place.
The actual shell patching stage remains intentionally deferred until the valid hook investigation protocol is satisfied.

This is the correct engineering direction because the Vita shell is firmware-dependent and not all render paths are safe for direct override.
