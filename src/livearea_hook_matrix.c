#include "livearea_hook_matrix.h"

#include <string.h>

int livearea_hook_matrix_init(LiveAreaHookMatrixEntry *entry)
{
    if (entry == NULL)
        return -1;

    memset(entry, 0, sizeof(*entry));
    entry->name = "unnamed";
    entry->category = "unknown";
    entry->risk = HOOK_RISK_HIGH;
    entry->firmware_checked = 0;
    entry->reversible = 0;
    entry->isolated = 0;
    entry->safe = 0;
    return 0;
}

int livearea_hook_matrix_set_candidate(LiveAreaHookMatrixEntry *entry,
                                     const char *name,
                                     const char *category,
                                     HookRiskLevel risk,
                                     int firmware_checked,
                                     int reversible,
                                     int isolated,
                                     int safe)
{
    if (entry == NULL)
        return -1;

    if (name != NULL)
        entry->name = name;

    if (category != NULL)
        entry->category = category;

    entry->risk = risk;
    entry->firmware_checked = firmware_checked;
    entry->reversible = reversible;
    entry->isolated = isolated;
    entry->safe = safe;
    return 0;
}

int livearea_hook_matrix_is_allowed(const LiveAreaHookMatrixEntry *entry)
{
    if (entry == NULL)
        return 0;

    if (entry->risk == HOOK_RISK_HIGH)
        return 0;

    if (entry->firmware_checked == 0)
        return 0;

    if (entry->reversible == 0)
        return 0;

    if (entry->isolated == 0)
        return 0;

    if (entry->safe == 0)
        return 0;

    return 1;
}
