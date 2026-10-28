#ifndef SELECTED_ICON_GLOW_VALIDATION_H
#define SELECTED_ICON_GLOW_VALIDATION_H

typedef enum SelectedIconGlowVerdict {
    SELECTED_ICON_GLOW_BLOCKED = 0,
    SELECTED_ICON_GLOW_REVIEW = 1,
    SELECTED_ICON_GLOW_ALLOWED = 2
} SelectedIconGlowVerdict;

typedef struct SelectedIconGlowValidation {
    const char *name;
    int risk_low;
    int firmware_checked;
    int local_scope;
    int reversible;
    int isolated;
    int safe;
    int fallback_active;
    SelectedIconGlowVerdict verdict;
} SelectedIconGlowValidation;

int selected_icon_glow_validation_init(SelectedIconGlowValidation *validation);
int selected_icon_glow_validation_evaluate(SelectedIconGlowValidation *validation);
int selected_icon_glow_validation_allow(SelectedIconGlowValidation *validation);
int selected_icon_glow_validation_block(SelectedIconGlowValidation *validation);
int selected_icon_glow_validation_review(SelectedIconGlowValidation *validation);

#endif // SELECTED_ICON_GLOW_VALIDATION_H
