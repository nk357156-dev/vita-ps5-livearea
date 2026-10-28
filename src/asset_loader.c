#include <psp2/types.h>

#include "asset_loader.h"

#define ASSET_PACK_NAME "default_ps5_like_pack"

static int g_assets_loaded = 0;

int asset_loader_init(void)
{
    g_assets_loaded = 0;
    return 0;
}

int asset_loader_load_default_pack(void)
{
    /*
     * Placeholder asset pipeline.
     * Real implementation will load UI textures, overlays, and font/material config.
     */
    g_assets_loaded = 1;
    return 0;
}

int asset_loader_unload(void)
{
    g_assets_loaded = 0;
    return 0;
}

int asset_loader_is_loaded(void)
{
    return g_assets_loaded;
}
