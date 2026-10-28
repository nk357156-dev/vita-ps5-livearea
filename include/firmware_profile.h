#ifndef FIRMWARE_PROFILE_H
#define FIRMWARE_PROFILE_H

#include <stdint.h>

#define FIRMWARE_PROFILE_NAME_MAX 32

typedef struct FirmwareProfile {
    char name[FIRMWARE_PROFILE_NAME_MAX];
    uint32_t module_nid;
    uint32_t expected_text_size;
    int retail;
    int pstv;
    int testkit;
    int devkit;
    int supports_theme_engine;
    int supports_custom_assets;
    int requires_fallback;
} FirmwareProfile;

int firmware_profile_match(const FirmwareProfile *profiles,
                           int profile_count,
                           uint32_t module_nid,
                           const FirmwareProfile **selected);

#endif // FIRMWARE_PROFILE_H
