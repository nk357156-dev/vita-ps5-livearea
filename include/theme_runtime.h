#ifndef THEME_RUNTIME_H
#define THEME_RUNTIME_H

#include "runtime_config.h"

typedef struct ThemeRuntime {
    RuntimeConfig config;
    int active;
    int fallback;
} ThemeRuntime;

int theme_runtime_init(ThemeRuntime *runtime);
int theme_runtime_apply_profile(ThemeRuntime *runtime, const ThemeProfile *profile);
int theme_runtime_enable_fallback(ThemeRuntime *runtime);
int theme_runtime_validate(ThemeRuntime *runtime);

#endif // THEME_RUNTIME_H
