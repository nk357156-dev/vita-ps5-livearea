#include <psp2/types.h>

#include "theme.h"

static VitaThemeConfig g_theme_config;

int theme_config_load_default(VitaThemeConfig *config)
{
    if (config == NULL)
        return -1;

    config->enable_glass_mode = 1;
    config->enable_neon_accent = 1;
    config->enable_dynamic_background = 0;
    config->enable_icon_recolor = 1;

    return 0;
}

int theme_patch_init(void)
{
    if (theme_config_load_default(&g_theme_config) < 0)
        return -1;

    return 0;
}

int theme_patch_start(void)
{
    /*
     * Placeholder for shell injection and style hooks.
     * The actual Vita shell patching will be implemented in later stages.
     */
    return 0;
}

int theme_patch_stop(void)
{
    return 0;
}

void theme_patch_cleanup(void)
{
    /* placeholder cleanup */
}
