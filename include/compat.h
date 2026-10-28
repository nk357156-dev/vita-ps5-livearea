#ifndef COMPAT_H
#define COMPAT_H

#include <psp2/types.h>

#define VITA_COMPAT_OK 0
#define VITA_COMPAT_FAIL -1
#define VITA_COMPAT_UNSUPPORTED -2

typedef struct FirmwareProfile {
    uint32_t module_nid;
    uint32_t expected_text_size;
    const char *name;
    int supports_theme_engine;
    int supports_custom_assets;
} FirmwareProfile;

int compat_init(void);
int compat_select_profile(const FirmwareProfile *profiles, int count, uint32_t module_nid, const FirmwareProfile **selected);
int compat_is_supported_profile(const FirmwareProfile *profile);

#endif // COMPAT_H
