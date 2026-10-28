#include "firmware_profile.h"

int firmware_profile_match(const FirmwareProfile *profiles,
                           int profile_count,
                           uint32_t module_nid,
                           const FirmwareProfile **selected)
{
    int i;

    if (profiles == NULL || selected == NULL || profile_count <= 0)
        return -1;

    *selected = NULL;

    for (i = 0; i < profile_count; ++i) {
        if (profiles[i].module_nid == module_nid) {
            *selected = &profiles[i];
            return 0;
        }
    }

    return -1;
}
