#include "theme_profile.h"

#include <stdio.h>
#include <string.h>

static void theme_palette_default(ThemePalette *palette)
{
    if (palette == NULL)
        return;

    palette->bg_base = 0x090B12u;
    palette->bg_surface = 0x121821u;
    palette->panel = 0x181F2Bu;
    palette->panel_frost = 0x1E2A3Au;
    palette->accent_primary = 0x5BC0FFu;
    palette->accent_secondary = 0x7F9BFFu;
    palette->glow_cyan = 0x72E5FFu;
    palette->text_primary = 0xF5F7FBu;
    palette->text_secondary = 0xB7C2D9u;
    palette->success = 0x7BE0A0u;
    palette->warning = 0xFFCC66u;
}

int theme_profile_init_default(ThemeProfile *profile)
{
    if (profile == NULL)
        return -1;

    memset(profile, 0, sizeof(*profile));

    snprintf(profile->name, sizeof(profile->name), "%s", "vita-ps5-livearea");
    snprintf(profile->style, sizeof(profile->style), "%s", THEME_STYLE_NEON);

    profile->enabled = THEME_PROFILE_ENABLED;
    profile->glass_mode = 1;
    profile->neon_accent = 1;
    profile->dynamic_background = 0;
    profile->custom_icons = 1;
    profile->ui_scale = 100;

    theme_palette_default(&profile->palette);
    return 0;
}

int theme_profile_set_style(ThemeProfile *profile, const char *style_name)
{
    if (profile == NULL || style_name == NULL)
        return -1;

    if (strcmp(style_name, THEME_STYLE_DEFAULT) == 0) {
        snprintf(profile->style, sizeof(profile->style), "%s", THEME_STYLE_DEFAULT);
        profile->glass_mode = 0;
        profile->neon_accent = 0;
        profile->dynamic_background = 0;
        return 0;
    }

    if (strcmp(style_name, THEME_STYLE_NEON) == 0) {
        snprintf(profile->style, sizeof(profile->style), "%s", THEME_STYLE_NEON);
        profile->glass_mode = 1;
        profile->neon_accent = 1;
        profile->dynamic_background = 0;
        return 0;
    }

    if (strcmp(style_name, THEME_STYLE_GLASS) == 0) {
        snprintf(profile->style, sizeof(profile->style), "%s", THEME_STYLE_GLASS);
        profile->glass_mode = 1;
        profile->neon_accent = 1;
        profile->dynamic_background = 1;
        return 0;
    }

    return -1;
}

int theme_profile_apply_palette(ThemeProfile *profile, const ThemePalette *palette)
{
    if (profile == NULL || palette == NULL)
        return -1;

    profile->palette = *palette;
    return 0;
}

int theme_profile_validate(const ThemeProfile *profile)
{
    if (profile == NULL)
        return -1;

    if (profile->name[0] == '\0')
        return -1;

    if (profile->style[0] == '\0')
        return -1;

    if (strcmp(profile->style, THEME_STYLE_DEFAULT) != 0 &&
        strcmp(profile->style, THEME_STYLE_NEON) != 0 &&
        strcmp(profile->style, THEME_STYLE_GLASS) != 0) {
        return -1;
    }

    if (profile->ui_scale < 80 || profile->ui_scale > 120)
        return -1;

    return 0;
}
