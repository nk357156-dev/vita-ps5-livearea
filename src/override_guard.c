#include "override_guard.h"

#include <string.h>

int override_guard_init(OverrideGuard *guard)
{
    if (guard == NULL)
        return -1;

    memset(guard, 0, sizeof(*guard));
    guard->firmware_valid = 0;
    guard->theme_valid = 0;
    guard->metadata_valid = 0;
    guard->hook_valid = 0;
    guard->fallback_active = 0;
    return 0;
}

int override_guard_set_firmware_valid(OverrideGuard *guard, int valid)
{
    if (guard == NULL)
        return -1;

    guard->firmware_valid = valid;
    return 0;
}

int override_guard_set_theme_valid(OverrideGuard *guard, int valid)
{
    if (guard == NULL)
        return -1;

    guard->theme_valid = valid;
    return 0;
}

int override_guard_set_metadata_valid(OverrideGuard *guard, int valid)
{
    if (guard == NULL)
        return -1;

    guard->metadata_valid = valid;
    return 0;
}

int override_guard_set_hook_valid(OverrideGuard *guard, int valid)
{
    if (guard == NULL)
        return -1;

    guard->hook_valid = valid;
    return 0;
}

int override_guard_evaluate(OverrideGuard *guard)
{
    if (guard == NULL)
        return -1;

    if (guard->firmware_valid == 0 ||
        guard->theme_valid == 0 ||
        guard->metadata_valid == 0 ||
        guard->hook_valid == 0)
    {
        guard->fallback_active = 1;
        return -1;
    }

    guard->fallback_active = 0;
    return 0;
}

int override_guard_enable_fallback(OverrideGuard *guard)
{
    if (guard == NULL)
        return -1;

    guard->fallback_active = 1;
    return 0;
}
