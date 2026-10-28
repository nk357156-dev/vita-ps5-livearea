#ifndef VALIDATION_RUNNER_H
#define VALIDATION_RUNNER_H

#include "asset_pack_metadata.h"
#include "theme_profile.h"

typedef struct ValidationResult {
    int ok;
    int error_count;
    char message[512];
} ValidationResult;

int validation_runner_init(ValidationResult *result);
int validation_runner_validate_profile(const ThemeProfile *profile, ValidationResult *result);
int validation_runner_validate_metadata(const AssetPackMetadata *metadata, ValidationResult *result);
int validation_runner_validate_full(const ThemeProfile *profile,
                                   const AssetPackMetadata *metadata,
                                   ValidationResult *result);

#endif // VALIDATION_RUNNER_H
