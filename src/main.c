#include <psp2/kernel/modulemgr.h>
#include <psp2/types.h>

#include "theme_runtime.h"
#include "theme_profile_loader.h"
#include "validation_runner.h"
#include "firmware_profile.h"
#include "override_guard.h"
#include "debug_log.h"

#define THEME_PROFILE_COUNT 3

static const FirmwareProfile g_profiles[] = {
    {
        .name = "retail-360",
        .module_nid = 0x0552F692u,
        .expected_text_size = 0x00000000u,
        .retail = 1,
        .pstv = 0,
        .testkit = 0,
        .devkit = 0,
        .supports_theme_engine = 1,
        .supports_custom_assets = 1,
        .requires_fallback = 0
    },
    {
        .name = "retail-365",
        .module_nid = 0x5549BF1Fu,
        .expected_text_size = 0x00000000u,
        .retail = 1,
        .pstv = 0,
        .testkit = 0,
        .devkit = 0,
        .supports_theme_engine = 1,
        .supports_custom_assets = 1,
        .requires_fallback = 0
    },
    {
        .name = "retail-373",
        .module_nid = 0x00000000u,
        .expected_text_size = 0x00000000u,
        .retail = 1,
        .pstv = 0,
        .testkit = 0,
        .devkit = 0,
        .supports_theme_engine = 0,
        .supports_custom_assets = 0,
        .requires_fallback = 1
    }
};

int module_start(SceSize argc, const void *args)
{
    ThemeRuntime runtime;
    ThemeProfile profile;
    ValidationResult result;
    OverrideGuard guard;
    const FirmwareProfile *matched = NULL;
    uint32_t fake_module_nid = 0x0552F692u;

    (void)argc;
    (void)args;

    debug_log_init();

    if (theme_runtime_init(&runtime) != 0) {
        debug_log_print("boot", "runtime init failed");
        return SCE_KERNEL_START_FAILED;
    }

    if (override_guard_init(&guard) != 0) {
        debug_log_print("boot", "override guard init failed");
        return SCE_KERNEL_START_FAILED;
    }

    if (theme_profile_load_json("ux0:/data/vita-ps5-livearea/profiles/neon-glass.json", &profile) != 0) {
        debug_log_print("boot", "theme profile load failed");
        override_guard_enable_fallback(&guard);
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    override_guard_set_theme_valid(&guard, 1);

    if (firmware_profile_match(g_profiles, THEME_PROFILE_COUNT, fake_module_nid, &matched) != 0) {
        debug_log_print("boot", "firmware profile match failed");
        override_guard_set_firmware_valid(&guard, 0);
        override_guard_enable_fallback(&guard);
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    if (matched == NULL || matched->supports_theme_engine == 0) {
        debug_log_print("boot", "unsupported firmware profile");
        override_guard_set_firmware_valid(&guard, 0);
        override_guard_enable_fallback(&guard);
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    override_guard_set_firmware_valid(&guard, 1);

    if (theme_runtime_apply_profile(&runtime, &profile) != 0) {
        debug_log_print("boot", "runtime profile apply failed");
        override_guard_enable_fallback(&guard);
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    if (theme_runtime_validate(&runtime) != 0) {
        debug_log_print("boot", "runtime validation failed");
        override_guard_enable_fallback(&guard);
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    if (validation_runner_validate_profile(&runtime.config.profile, &result) != 0) {
        debug_log_print("boot", "validation runner failed");
        override_guard_enable_fallback(&guard);
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    override_guard_set_metadata_valid(&guard, 1);
    override_guard_set_hook_valid(&guard, 1);

    if (override_guard_evaluate(&guard) != 0) {
        debug_log_print("boot", "guard evaluation failed, fallback active");
        theme_runtime_enable_fallback(&runtime);
        return SCE_KERNEL_START_SUCCESS;
    }

    debug_log_print("boot", "safe runtime activation passed");

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args)
{
    (void)argc;
    (void)args;
    return SCE_KERNEL_STOP_SUCCESS;
}
