#ifndef THEME_RUNTIME_H
#define THEME_RUNTIME_H

#include <psp2/types.h>

#define VITA_THEME_NAME "vita_ps5_livearea"
#define VITA_THEME_VERSION "0.1.0"

#define VITA_THEME_STYLE_DEFAULT 0
#define VITA_THEME_STYLE_NEON 1
#define VITA_THEME_STYLE_GLASS 2

typedef struct VitaThemeRuntime {
    int enabled;
    int style;
    int neon_enabled;
    int glass_enabled;
    int dynamic_background;
    int custom_icons;
    int ui_scale;
} VitaThemeRuntime;

int theme_runtime_init(VitaThemeRuntime *runtime);
int theme_runtime_apply_default(VitaThemeRuntime *runtime);
int theme_runtime_set_style(VitaThemeRuntime *runtime, int style);
void theme_runtime_cleanup(VitaThemeRuntime *runtime);

#endif // THEME_RUNTIME_H
