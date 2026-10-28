#include <psp2/types.h>

#include "compat.h"

int compat_init(void)
{
    return VITA_COMPAT_OK;
}

int compat_select_profile(const FirmwareProfile *profiles,
    int count, uint32_t module_nid, const FirmwareProfile **selected)
{
    int index;

    if (profiles == NULL || selected == NULL || count <= 0)
        return VITA_COMPAT_FAIL;

    *selected = NULL;

    for (index = 0; index < count; ++index) {
        if (profiles[index].module_nid == module_nid) {
            *selected = &profiles[index];
            return VITA_COMPAT_OK;
        }
    }

    return VITA_COMPAT_UNSUPPORTED;
}

int compat_is_supported_profile(const FirmwareProfile *profile)
{
    if (profile == NULL)
        return 0;

    return profile->supports_theme_engine && profile->supports_custom_assets;
}
