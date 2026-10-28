#include "theme_loader.h"

#include <stdio.h>
#include <string.h>

int theme_loader_init(ThemeLoadResult *result)
{
    if (result == NULL)
        return -1;

    memset(result, 0, sizeof(*result));
    result->ok = 1;
    result->fallback = 0;
    snprintf(result->message, sizeof(result->message), "%s", "theme loader initialized");
    return 0;
}

int theme_loader_load_default(ThemeLoadResult *result, RuntimeConfig *config)
{
    ThemeProfile profile;

    if (result == NULL || config == NULL)
        return -1;

    memset(result, 0, sizeof(*result));

    if (theme_profile_init_default(&profile) != 0) {
        result->ok = 0;
        result->fallback = 1;
        snprintf(result->message, sizeof(result->message), "%s", "theme_profile_init_default failed");
        return -1;
    }

    if (runtime_config_apply_profile(config, &profile) != 0) {
        result->ok = 0;
        result->fallback = 1;
        snprintf(result->message, sizeof(result->message), "%s", "runtime_config_apply_profile failed");
        return -1;
    }

    result->ok = 1;
    result->fallback = 0;
    snprintf(result->message, sizeof(result->message), "%s", "default theme profile loaded");
    return 0;
}

int theme_loader_apply_profile(RuntimeConfig *config, const ThemeProfile *profile, ThemeLoadResult *result)
{
    if (config == NULL || profile == NULL || result == NULL)
        return -1;

    memset(result, 0, sizeof(*result));

    if (theme_profile_validate(profile) != 0) {
        result->ok = 0;
        result->fallback = 1;
        snprintf(result->message, sizeof(result->message), "%s", "invalid theme profile; falling back to stock");
        return -1;
    }

    if (runtime_config_apply_profile(config, profile) != 0) {
        result->ok = 0;
        result->fallback = 1;
        snprintf(result->message, sizeof(result->message), "%s", "runtime_config_apply_profile failed");
        return -1;
    }

    result->ok = 1;
    result->fallback = 0;
    snprintf(result->message, sizeof(result->message), "profile applied: %s", profile->name);
    return 0;
}
