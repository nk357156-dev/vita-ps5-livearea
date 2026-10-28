#ifndef RUNTIME_CONFIG_H
#define RUNTIME_CONFIG_H

#include "theme_profile.h"

#define RUNTIME_CONFIG_NAME_MAX 64

typedef struct RuntimeConfig {
    char name[RUNTIME_CONFIG_NAME_MAX];
    int enabled;
    int fallback_enabled;
    int custom_theme_loaded;
    int validation_ok;
    ThemeProfile profile;
} RuntimeConfig;

int runtime_config_init(RuntimeConfig *config);
int runtime_config_apply_profile(RuntimeConfig *config, const ThemeProfile *profile);
int runtime_config_enable_fallback(RuntimeConfig *config, int enabled);
int runtime_config_validate(RuntimeConfig *config);

#endif // RUNTIME_CONFIG_H
