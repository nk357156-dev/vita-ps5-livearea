#include <stdint.h>

static const uint8_t patch_placeholder[4] = {0x00, 0x00, 0x00, 0x00};

void theme_patch_bytes_placeholder(void)
{
    /*
     * This placeholder exists so the build can keep an ASM patch file
     * with a clear separation from the high-level C implementation.
     */
    (void)patch_placeholder;
}
