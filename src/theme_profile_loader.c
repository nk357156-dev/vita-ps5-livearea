#include "theme_profile_loader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void trim_token(char *s)
{
    size_t len;
    char *p;

    if (s == NULL)
        return;

    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '"')
        s++;

    p = s;
    len = strlen(p);

    while (len > 0 && (p[len - 1] == ' ' || p[len - 1] == '\t' ||
                       p[len - 1] == '\n' || p[len - 1] == '\r' ||
                       p[len - 1] == '"' || p[len - 1] == ',' ||
                       p[len - 1] == '}' || p[len - 1] == ']'))
    {
        p[len - 1] = '\0';
        len--;
    }

    if (p != s)
        memmove(s, p, len + 1);
}

static int hex_to_u32(const char *hex, uint32_t *out)
{
    char *end = NULL;
    unsigned long value;

    if (hex == NULL || out == NULL)
        return -1;

    while (*hex == ' ' || *hex == '\t' || *hex == '\n' || *hex == '\r')
        hex++;

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
        hex += 2;

    value = strtoul(hex, &end, 16);
    if (end == hex || *end != '\0')
        return -1;

    *out = (uint32_t)value;
    return 0;
}

static int parse_palette_field(const char *key, const char *value, ThemePalette *palette)
{
    if (palette == NULL || key == NULL || value == NULL)
        return -1;

    if (strcmp(key, "bg_base") == 0)
        return hex_to_u32(value, &palette->bg_base);
    if (strcmp(key, "bg_surface") == 0)
        return hex_to_u32(value, &palette->bg_surface);
    if (strcmp(key, "panel") == 0)
        return hex_to_u32(value, &palette->panel);
    if (strcmp(key, "panel_frost") == 0)
        return hex_to_u32(value, &palette->panel_frost);
    if (strcmp(key, "accent_primary") == 0)
        return hex_to_u32(value, &palette->accent_primary);
    if (strcmp(key, "accent_secondary") == 0)
        return hex_to_u32(value, &palette->accent_secondary);
    if (strcmp(key, "glow_cyan") == 0)
        return hex_to_u32(value, &palette->glow_cyan);
    if (strcmp(key, "text_primary") == 0)
        return hex_to_u32(value, &palette->text_primary);
    if (strcmp(key, "text_secondary") == 0)
        return hex_to_u32(value, &palette->text_secondary);
    if (strcmp(key, "success") == 0)
        return hex_to_u32(value, &palette->success);
    if (strcmp(key, "warning") == 0)
        return hex_to_u32(value, &palette->warning);

    return -1;
}

int theme_profile_load_json(const char *path, ThemeProfile *profile)
{
    FILE *fp;
    char line[512];
    ThemePalette palette;
    int found_name = 0;
    int found_style = 0;
    int found_enabled = 0;
    int found_glass = 0;
    int found_neon = 0;
    int found_icons = 0;
    int found_scale = 0;

    if (path == NULL || profile == NULL)
        return -1;

    memset(profile, 0, sizeof(*profile));
    memset(&palette, 0, sizeof(palette));

    fp = fopen(path, "r");
    if (fp == NULL)
        return -1;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *colon = strchr(line, ':');
        char *key;
        char *value;

        if (colon == NULL)
            continue;

        *colon = '\0';
        key = line;
        value = colon + 1;

        trim_token(key);
        trim_token(value);

        if (strcmp(key, "name") == 0) {
            snprintf(profile->name, sizeof(profile->name), "%s", value);
            found_name = 1;
        } else if (strcmp(key, "style") == 0) {
            snprintf(profile->style, sizeof(profile->style), "%s", value);
            found_style = 1;
        } else if (strcmp(key, "enabled") == 0) {
            profile->enabled = (strcmp(value, "true") == 0) ? 1 : 0;
            found_enabled = 1;
        } else if (strcmp(key, "glass_mode") == 0) {
            profile->glass_mode = (strcmp(value, "true") == 0) ? 1 : 0;
            found_glass = 1;
        } else if (strcmp(key, "neon_accent") == 0) {
            profile->neon_accent = (strcmp(value, "true") == 0) ? 1 : 0;
            found_neon = 1;
        } else if (strcmp(key, "dynamic_background") == 0) {
            profile->dynamic_background = (strcmp(value, "true") == 0) ? 1 : 0;
        } else if (strcmp(key, "custom_icons") == 0) {
            profile->custom_icons = (strcmp(value, "true") == 0) ? 1 : 0;
            found_icons = 1;
        } else if (strcmp(key, "ui_scale") == 0) {
            profile->ui_scale = (int)strtol(value, NULL, 10);
            found_scale = 1;
        } else if (strcmp(key, "bg_base") == 0) {
            parse_palette_field("bg_base", value, &palette);
        } else if (strcmp(key, "bg_surface") == 0) {
            parse_palette_field("bg_surface", value, &palette);
        } else if (strcmp(key, "panel") == 0) {
            parse_palette_field("panel", value, &palette);
        } else if (strcmp(key, "panel_frost") == 0) {
            parse_palette_field("panel_frost", value, &palette);
        } else if (strcmp(key, "accent_primary") == 0) {
            parse_palette_field("accent_primary", value, &palette);
        } else if (strcmp(key, "accent_secondary") == 0) {
            parse_palette_field("accent_secondary", value, &palette);
        } else if (strcmp(key, "glow_cyan") == 0) {
            parse_palette_field("glow_cyan", value, &palette);
        } else if (strcmp(key, "text_primary") == 0) {
            parse_palette_field("text_primary", value, &palette);
        } else if (strcmp(key, "text_secondary") == 0) {
            parse_palette_field("text_secondary", value, &palette);
        } else if (strcmp(key, "success") == 0) {
            parse_palette_field("success", value, &palette);
        } else if (strcmp(key, "warning") == 0) {
            parse_palette_field("warning", value, &palette);
        }
    }

    fclose(fp);
    profile->palette = palette;

    if (!found_name || !found_style || !found_enabled || !found_glass ||
        !found_neon || !found_icons || !found_scale)
    {
        return -1;
    }

    if (theme_profile_validate(profile) != 0)
        return -1;

    return 0;
}

int theme_metadata_load_json(const char *path, AssetPackMetadata *metadata)
{
    FILE *fp;
    char line[512];
    int firmware_count = 0;
    int found_name = 0;
    int found_version = 0;
    int found_style = 0;
    int found_fallback = 0;
    int found_fallback_enabled = 0;
    int found_background = 0;
    int found_icons = 0;
    int found_labels = 0;

    if (path == NULL || metadata == NULL)
        return -1;

    memset(metadata, 0, sizeof(*metadata));

    fp = fopen(path, "r");
    if (fp == NULL)
        return -1;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *colon = strchr(line, ':');
        char *key;
        char *value;

        if (colon == NULL)
            continue;

        *colon = '\0';
        key = line;
        value = colon + 1;

        trim_token(key);
        trim_token(value);

        if (strcmp(key, "theme_name") == 0) {
            snprintf(metadata->theme_name, sizeof(metadata->theme_name), "%s", value);
            found_name = 1;
        } else if (strcmp(key, "version") == 0) {
            snprintf(metadata->version, sizeof(metadata->version), "%s", value);
            found_version = 1;
        } else if (strcmp(key, "style") == 0) {
            snprintf(metadata->style, sizeof(metadata->style), "%s", value);
            found_style = 1;
        } else if (strcmp(key, "fallback_mode") == 0) {
            snprintf(metadata->fallback_mode, sizeof(metadata->fallback_mode), "%s", value);
            found_fallback = 1;
        } else if (strcmp(key, "fallback_enabled") == 0) {
            metadata->fallback_enabled = (strcmp(value, "true") == 0) ? 1 : 0;
            found_fallback_enabled = 1;
        } else if (strcmp(key, "requires_background") == 0) {
            metadata->requires_background = (strcmp(value, "true") == 0) ? 1 : 0;
            found_background = 1;
        } else if (strcmp(key, "requires_overlays") == 0) {
            metadata->requires_overlays = (strcmp(value, "true") == 0) ? 1 : 0;
        } else if (strcmp(key, "requires_icons") == 0) {
            metadata->requires_icons = (strcmp(value, "true") == 0) ? 1 : 0;
            found_icons = 1;
        } else if (strcmp(key, "requires_labels") == 0) {
            metadata->requires_labels = (strcmp(value, "true") == 0) ? 1 : 0;
            found_labels = 1;
        } else if (strcmp(key, "supported_firmware") == 0) {
            /* array handled by next entries */
        } else if (strlen(value) > 0 && firmware_count < ASSET_PACK_FIRMWARE_MAX) {
            snprintf(metadata->supported_firmware[firmware_count],
                     sizeof(metadata->supported_firmware[firmware_count]), "%s", value);
            firmware_count++;
        }
    }

    fclose(fp);
    metadata->supported_firmware_count = firmware_count;

    if (!found_name || !found_version || !found_style || !found_fallback ||
        !found_fallback_enabled || !found_background || !found_icons ||
        !found_labels || metadata->supported_firmware_count <= 0)
    {
        return -1;
    }

    return 0;
}
