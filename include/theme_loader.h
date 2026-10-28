#ifndef THEME_LOADER_H
#define THEME_LOADER_H

#include "theme_profile.h"
#include "runtime_config.h"

typedef struct ThemeLoadResult {
    int ok;
    int fallback;
    char message[256];
} ThemeLoadResult;

int theme_loader_init(ThemeLoadResult *result);
int theme_loader_load_default(ThemeLoadResult *result, RuntimeConfig *config);
int theme_loader_apply_profile(RuntimeConfig *config, const ThemeProfile *profile, ThemeLoadResult *result);

#endif // THEME_LOADER_H
