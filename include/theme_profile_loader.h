#ifndef THEME_PROFILE_LOADER_H
#define THEME_PROFILE_LOADER_H

#include "asset_pack_metadata.h"
#include "theme_profile.h"

int theme_profile_load_json(const char *path, ThemeProfile *profile);
int theme_metadata_load_json(const char *path, AssetPackMetadata *metadata);

#endif // THEME_PROFILE_LOADER_H
