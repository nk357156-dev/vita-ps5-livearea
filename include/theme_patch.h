#ifndef THEME_PATCH_H
#define THEME_PATCH_H

#include <psp2/types.h>

#define VITA_THEME_PATCH_OK 0
#define VITA_THEME_PATCH_FAIL -1
#define VITA_THEME_PATCH_UNSUPPORTED -2

typedef struct VitaThemePatchProfile {
    uint32_t module_nid;
    uint32_t text_size;
    const char *name;
} VitaThemePatchProfile;

int theme_patch_init(void);
int theme_patch_apply_profile(const VitaThemePatchProfile *profile);
int theme_patch_release(void);
int theme_patch_is_active(void);

#endif // THEME_PATCH_H
