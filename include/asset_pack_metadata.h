#ifndef ASSET_PACK_METADATA_H
#define ASSET_PACK_METADATA_H

#include <stdint.h>

#define ASSET_PACK_NAME_MAX 64
#define ASSET_PACK_VERSION_MAX 32
#define ASSET_PACK_STYLE_MAX 24
#define ASSET_PACK_FIRMWARE_MAX 16
#define ASSET_PACK_REQUIRED_ASSET_MAX 8

typedef struct AssetPackMetadata {
    char theme_name[ASSET_PACK_NAME_MAX];
    char version[ASSET_PACK_VERSION_MAX];
    char style[ASSET_PACK_STYLE_MAX];
    char fallback_mode[ASSET_PACK_NAME_MAX];
    int fallback_enabled;
    int requires_background;
    int requires_overlays;
    int requires_icons;
    int requires_labels;
    char supported_firmware[ASSET_PACK_FIRMWARE_MAX][16];
    int supported_firmware_count;
} AssetPackMetadata;

#endif // ASSET_PACK_METADATA_H
