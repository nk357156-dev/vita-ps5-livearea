#include <psp2/types.h>

#include "theme_runtime.h"

int theme_runtime_init(VitaThemeRuntime *runtime)
{
    if (runtime == NULL)
        return -1;

    runtime->enabled = 1;
    runtime->style = VITA_THEME_STYLE_NEON;
    runtime->neon_enabled = 1;
    runtime->glass_enabled = 1;
    runtime->dynamic_background = 0;
    runtime->custom_icons = 1;
    runtime->ui_scale = 100;

    return 0;
}

int theme_runtime_apply_default(VitaThemeRuntime *runtime)
{
    if (runtime == NULL)
        return -1;

    return theme_runtime_set_style(runtime, VITA_THEME_STYLE_NEON);
}

int theme_runtime_set_style(VitaThemeRuntime *runtime, int style)
{
    if (runtime == NULL)
        return -1;

    if (style < VITA_THEME_STYLE_DEFAULT || style > VITA_THEME_STYLE_GLASS)
        return -1;

    runtime->style = style;
    runtime->neon_enabled = (style != VITA_THEME_STYLE_DEFAULT);
    runtime->glass_enabled = (style == VITA_THEME_STYLE_GLASS || style == VITA_THEME_STYLE_NEON);

    return 0;
}

void theme_runtime_cleanup(VitaThemeRuntime *runtime)
{
    if (runtime == NULL)
        return;

    runtime->enabled = 0;
    runtime->style = VITA_THEME_STYLE_DEFAULT;
    runtime->ui_scale = 100;
}
