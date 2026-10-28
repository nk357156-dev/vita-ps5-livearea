#ifndef THEME_H
#define THEME_H

#include <psp2/types.h>

#define VITA_PS5_THEME_NAME "vita_ps5_livearea"
#define VITA_PS5_THEME_VERSION "0.1.0"

typedef struct VitaThemeConfig {
    int enable_glass_mode;
    int enable_neon_accent;
    int enable_dynamic_background;
    int enable_icon_recolor;
} VitaThemeConfig;

int theme_patch_init(void);
int theme_patch_start(void);
int theme_patch_stop(void);
void theme_patch_cleanup(void);

int theme_config_load_default(VitaThemeConfig *config);

#endif // THEME_H
