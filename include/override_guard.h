#ifndef OVERRIDE_GUARD_H
#define OVERRIDE_GUARD_H

typedef struct OverrideGuard {
    int firmware_valid;
    int theme_valid;
    int metadata_valid;
    int hook_valid;
    int fallback_active;
} OverrideGuard;

int override_guard_init(OverrideGuard *guard);
int override_guard_set_firmware_valid(OverrideGuard *guard, int valid);
int override_guard_set_theme_valid(OverrideGuard *guard, int valid);
int override_guard_set_metadata_valid(OverrideGuard *guard, int valid);
int override_guard_set_hook_valid(OverrideGuard *guard, int valid);
int override_guard_evaluate(OverrideGuard *guard);
int override_guard_enable_fallback(OverrideGuard *guard);

#endif // OVERRIDE_GUARD_H
