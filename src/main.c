#include <psp2/kernel/modulemgr.h>
#include <psp2/types.h>
#include <stdint.h>

#include "theme.h"
#include "asset_loader.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int module_start(SceSize argc, const void *args)
{
    (void)argc;
    (void)args;

    if (asset_loader_init() < 0)
        return SCE_KERNEL_START_FAILED;

    if (asset_loader_load_default_pack() < 0)
        return SCE_KERNEL_START_FAILED;

    if (theme_patch_init() < 0)
        return SCE_KERNEL_START_FAILED;

    if (theme_patch_start() < 0)
        return SCE_KERNEL_START_FAILED;

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args)
{
    (void)argc;
    (void)args;

    theme_patch_stop();
    theme_patch_cleanup();
    asset_loader_unload();

    return SCE_KERNEL_STOP_SUCCESS;
}
