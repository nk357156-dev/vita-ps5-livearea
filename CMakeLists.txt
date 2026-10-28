cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if(DEFINED ENV{VITASDK})
        set(CMAKE_TOOLCHAIN_FILE
            "$ENV{VITASDK}/share/vita.toolchain.cmake"
            CACHE PATH "VitaSDK toolchain file")
    else()
        message(FATAL_ERROR "Set VITASDK or CMAKE_TOOLCHAIN_FILE")
    endif()
endif()

project(vita_ps5_livearea VERSION 0.2.0 LANGUAGES C ASM)
include("${VITASDK}/share/vita.cmake" REQUIRED)

option(VITA_PS5_THEME_DEBUG "Enable debug logging" OFF)

add_executable(vita_ps5_livearea
    src/main.c
    src/theme_patch.c
    src/theme_runtime.c
    src/theme_profile.c
    src/theme_profile_loader.c
    src/runtime_config.c
    src/asset_loader.c
    src/compat.c
    src/validation_runner.c
    src/firmware_profile.c
    src/theme_loader.c
    src/fallback.c
    src/override_guard.c
    src/debug_log.c
    src/livearea_hook_guard.c
    src/livearea_hook_matrix.c
    src/livearea_hook_policy.c
    src/selected_icon_glow_validation.c
    src/patch_bytes.S
)

target_include_directories(vita_ps5_livearea PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(vita_ps5_livearea PRIVATE
    -Wall
    -Wextra
    -Werror
    -O2
    -fno-pic
    -fno-PIC
)

target_link_libraries(vita_ps5_livearea
    taihen_stub
    SceKernelModulemgr_stub
    SceKernelThreadMgr_stub
    SceLibKernel_stub
    c
    gcc
)

set_target_properties(vita_ps5_livearea PROPERTIES
    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    LINK_FLAGS "-nostdlib -Wl,-q"
)

if(VITA_PS5_THEME_DEBUG)
    target_compile_definitions(vita_ps5_livearea PRIVATE VITA_PS5_THEME_DEBUG=1)
endif()

vita_create_self(vita_ps5_livearea.suprx vita_ps5_livearea
    UNSAFE
    CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/vita_ps5_livearea.yml
)
