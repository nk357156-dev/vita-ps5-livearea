#include "theme_profile.h"

#include <stdint.h>

#ifndef THEME_PROFILE_DEFAULTS
#define THEME_PROFILE_DEFAULTS

static const ThemeProfile g_default_profile = {
    .name = "vita-ps5-livearea",
    .style = "neon",
    .enabled = 1,
    .glass_mode = 1,
    .neon_accent = 1,
    .dynamic_background = 0,
    .custom_icons = 1,
    .ui_scale = 100,
    .palette = {
        .bg_base = 0x090B12u,
        .bg_surface = 0x121821u,
        .panel = 0x181F2Bu,
        .panel_frost = 0x1E2A3Au,
        .accent_primary = 0x5BC0FFu,
        .accent_secondary = 0x7F9BFFu,
        .glow_cyan = 0x72E5FFu,
        .text_primary = 0xF5F7FBu,
        .text_secondary = 0xB7C2D9u,
        .success = 0x7BE0A0u,
        .warning = 0xFFCC66u
    }
};

#endif
