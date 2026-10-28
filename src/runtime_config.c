#include "runtime_config.h"

#include <stdio.h>
#include <string.h>

int runtime_config_init(RuntimeConfig *config)
{
    if (config == NULL)
        return -1;

    memset(config, 0, sizeof(*config));

    snprintf(config->name, sizeof(config->name), "%s", "vita-ps5-livearea");
    config->enabled = 1;
    config->fallback_enabled = 1;
    config->custom_theme_loaded = 0;
    config->validation_ok = 0;

    if (theme_profile_init_default(&config->profile) != 0)
        return -1;

    return 0;
}

int runtime_config_apply_profile(RuntimeConfig *config, const ThemeProfile *profile)
{
    if (config == NULL || profile == NULL)
        return -1;

    config->profile = *profile;
    config->custom_theme_loaded = 1;
    config->validation_ok = 1;
    return 0;
}

int runtime_config_enable_fallback(RuntimeConfig *config, int enabled)
{
    if (config == NULL)
        return -1;

    config->fallback_enabled = enabled;
    return 0;
}

int runtime_config_validate(RuntimeConfig *config)
{
    if (config == NULL)
        return -1;

    if (theme_profile_validate(&config->profile) != 0) {
        config->validation_ok = 0;
        return -1;
    }

    config->validation_ok = 1;
    return 0;
}
