# Firmware profile model

## Goal

Create a simple, firmware-aware model for selecting UI behavior without assuming all Vita builds behave identically.

## Profile model structure

Each profile should include:
- firmware version
- hardware class (retail, PSTV, testkit, devkit)
- module NID
- expected text size
- validation state
- patch compatibility status
- fallback enabled/disabled

## Example model

```c
typedef struct FirmwareProfile {
    const char *name;
    uint32_t firmware_version;
    uint32_t module_nid;
    uint32_t expected_text_size;
    int supports_theme_engine;
    int supports_custom_assets;
    int requires_fallback;
} FirmwareProfile;
```

## Recommended profile order

Use this order when testing:
1. retail 3.60
2. retail 3.65
3. retail 3.73
4. PSTV 3.74 if available
5. devkit/testkit profiles later

## Rules

- one unsupported profile should not block all others
- a single known-good profile is enough as a baseline milestone
- unsupported profiles use stock theme rendering only
- keep the model explicit and easy to expand
