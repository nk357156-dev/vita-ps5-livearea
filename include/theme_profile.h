#ifndef THEME_PROFILE_H
#define THEME_PROFILE_H

#include <stdint.h>

#define THEME_NAME_MAX 64
#define THEME_STYLE_MAX 16

#define THEME_PROFILE_DEFAULT 0
#define THEME_PROFILE_NEON 1
#define THEME_PROFILE_GLASS 2

#define THEME_PROFILE_VALID 1
#define THEME_PROFILE_DISABLED 0

typedef struct ThemePalette {
    uint32_t bg_base;
    uint32_t bg_surface;
    uint32_t panel;
    uint32_t panel_frost;
    uint32_t accent_primary;
    uint32_t accent_secondary;
    uint32_t glow_cyan;
    uint32_t text_primary;
    uint32_t text_secondary;
    uint32_t success;
    uint32_t warning;
} ThemePalette;

typedef struct ThemeProfile {
    char name[THEME_NAME_MAX];
    char style[THEME_STYLE_MAX];
    int enabled;
    int glass_mode;
    int neon_accent;
    int dynamic_background;
    int custom_icons;
    int ui_scale;
    ThemePalette palette;
} ThemeProfile;

int theme_profile_init_default(ThemeProfile *profile);
int theme_profile_set_style(ThemeProfile *profile, const char *style_name);
int theme_profile_apply_palette(ThemeProfile *profile, const ThemePalette *palette);

#endif // THEME_PROFILE_H
