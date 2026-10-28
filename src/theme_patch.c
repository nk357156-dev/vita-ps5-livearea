#include <psp2/types.h>

#include "theme_patch.h"

static int g_patch_active = 0;

int theme_patch_init(void)
{
    g_patch_active = 0;
    return VITA_THEME_PATCH_OK;
}

int theme_patch_apply_profile(const VitaThemePatchProfile *profile)
{
    if (profile == NULL)
        return VITA_THEME_PATCH_FAIL;

    /*
     * Placeholder implementation.
     * Real logic should validate the shell module, text segment,
     * and generate reversible hook injection points.
     */
    g_patch_active = 1;
    return VITA_THEME_PATCH_OK;
}

int theme_patch_release(void)
{
    g_patch_active = 0;
    return VITA_THEME_PATCH_OK;
}

int theme_patch_is_active(void)
{
    return g_patch_active;
}
