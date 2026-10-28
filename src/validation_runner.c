#include "validation_runner.h"

#include <stdio.h>
#include <string.h>

int validation_runner_init(ValidationResult *result)
{
    if (result == NULL)
        return -1;

    memset(result, 0, sizeof(*result));
    result->ok = 1;
    snprintf(result->message, sizeof(result->message), "%s", "validation ok");
    return 0;
}

int validation_runner_validate_profile(const ThemeProfile *profile, ValidationResult *result)
{
    if (result == NULL)
        return -1;

    memset(result, 0, sizeof(*result));
    result->ok = 1;

    if (profile == NULL) {
        result->ok = 0;
        result->error_count = 1;
        snprintf(result->message, sizeof(result->message), "%s", "profile is NULL");
        return -1;
    }

    if (theme_profile_validate(profile) != 0) {
        result->ok = 0;
        result->error_count = 1;
        snprintf(result->message, sizeof(result->message), "%s", "profile validation failed");
        return -1;
    }

    snprintf(result->message, sizeof(result->message), "theme profile valid: %s", profile->name);
    return 0;
}

int validation_runner_validate_metadata(const AssetPackMetadata *metadata, ValidationResult *result)
{
    int i;

    if (result == NULL)
        return -1;

    memset(result, 0, sizeof(*result));
    result->ok = 1;

    if (metadata == NULL) {
        result->ok = 0;
        result->error_count = 1;
        snprintf(result->message, sizeof(result->message), "%s", "metadata is NULL");
        return -1;
    }

    if (metadata->theme_name[0] == '\0') {
        result->ok = 0;
        result->error_count++;
        snprintf(result->message, sizeof(result->message), "%s", "theme name is empty");
        return -1;
    }

    if (metadata->version[0] == '\0') {
        result->ok = 0;
        result->error_count++;
        snprintf(result->message, sizeof(result->message), "%s", "version is empty");
        return -1;
    }

    if (metadata->style[0] == '\0') {
        result->ok = 0;
        result->error_count++;
        snprintf(result->message, sizeof(result->message), "%s", "style is empty");
        return -1;
    }

    if (metadata->supported_firmware_count <= 0) {
        result->ok = 0;
        result->error_count++;
        snprintf(result->message, sizeof(result->message), "%s", "supported firmware count is invalid");
        return -1;
    }

    for (i = 0; i < metadata->supported_firmware_count; ++i) {
        if (metadata->supported_firmware[i][0] == '\0') {
            result->ok = 0;
            result->error_count++;
            snprintf(result->message, sizeof(result->message), "supported firmware entry %d is empty", i);
            return -1;
        }
    }

    snprintf(result->message, sizeof(result->message), "asset metadata valid for %s", metadata->theme_name);
    return 0;
}

int validation_runner_validate_full(const ThemeProfile *profile,
                                   const AssetPackMetadata *metadata,
                                   ValidationResult *result)
{
    if (result == NULL)
        return -1;

    memset(result, 0, sizeof(*result));
    result->ok = 1;

    if (validation_runner_validate_profile(profile, result) != 0)
        return -1;

    if (validation_runner_validate_metadata(metadata, result) != 0)
        return -1;

    snprintf(result->message, sizeof(result->message), "%s", "theme profile and asset metadata are valid");
    result->ok = 1;
    return 0;
}
