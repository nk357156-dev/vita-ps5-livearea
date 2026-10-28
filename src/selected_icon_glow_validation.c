#include "selected_icon_glow_validation.h"

#include <string.h>

int selected_icon_glow_validation_init(SelectedIconGlowValidation *validation)
{
    if (validation == NULL)
        return -1;

    memset(validation, 0, sizeof(*validation));
    validation->name = "selected_icon_glow";
    validation->risk_low = 1;
    validation->firmware_checked = 0;
    validation->local_scope = 0;
    validation->reversible = 0;
    validation->isolated = 0;
    validation->safe = 0;
    validation->fallback_active = 0;
    validation->verdict = SELECTED_ICON_GLOW_BLOCKED;
    return 0;
}

int selected_icon_glow_validation_evaluate(SelectedIconGlowValidation *validation)
{
    if (validation == NULL)
        return -1;

    if (validation->risk_low == 0) {
        validation->verdict = SELECTED_ICON_GLOW_BLOCKED;
        return -1;
    }

    if (validation->firmware_checked == 0 ||
        validation->local_scope == 0 ||
        validation->reversible == 0 ||
        validation->isolated == 0 ||
        validation->safe == 0 ||
        validation->fallback_active == 0) {
        validation->verdict = SELECTED_ICON_GLOW_REVIEW;
        return -1;
    }

    validation->verdict = SELECTED_ICON_GLOW_ALLOWED;
    return 0;
}

int selected_icon_glow_validation_allow(SelectedIconGlowValidation *validation)
{
    if (validation == NULL)
        return -1;

    validation->risk_low = 1;
    validation->firmware_checked = 1;
    validation->local_scope = 1;
    validation->reversible = 1;
    validation->isolated = 1;
    validation->safe = 1;
    validation->fallback_active = 1;
    validation->verdict = SELECTED_ICON_GLOW_ALLOWED;
    return 0;
}

int selected_icon_glow_validation_block(SelectedIconGlowValidation *validation)
{
    if (validation == NULL)
        return -1;

    validation->verdict = SELECTED_ICON_GLOW_BLOCKED;
    return 0;
}

int selected_icon_glow_validation_review(SelectedIconGlowValidation *validation)
{
    if (validation == NULL)
        return -1;

    validation->verdict = SELECTED_ICON_GLOW_REVIEW;
    return 0;
}
