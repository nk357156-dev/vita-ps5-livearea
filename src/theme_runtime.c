#include "theme_runtime.h"

#include <string.h>

int theme_runtime_init(ThemeRuntime *runtime)
{
    if (runtime == NULL)
        return -1;

    memset(runtime, 0, sizeof(*runtime));

    if (runtime_config_init(&runtime->config) != 0)
        return -1;

    runtime->active = 0;
    runtime->fallback = 0;
    return 0;
}

int theme_runtime_apply_profile(ThemeRuntime *runtime, const ThemeProfile *profile)
{
    if (runtime == NULL || profile == NULL)
        return -1;

    if (theme_profile_validate(profile) != 0)
        return -1;

    if (runtime_config_apply_profile(&runtime->config, profile) != 0)
        return -1;

    runtime->active = 1;
    runtime->fallback = 0;
    return 0;
}

int theme_runtime_enable_fallback(ThemeRuntime *runtime)
{
    if (runtime == NULL)
        return -1;

    runtime->fallback = 1;
    runtime->active = 0;
    runtime_config_enable_fallback(&runtime->config, 1);
    return 0;
}

int theme_runtime_validate(ThemeRuntime *runtime)
{
    if (runtime == NULL)
        return -1;

    if (runtime_config_validate(&runtime->config) != 0)
        return -1;

    return 0;
}
