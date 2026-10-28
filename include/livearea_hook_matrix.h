#ifndef LIVEAREA_HOOK_MATRIX_H
#define LIVEAREA_HOOK_MATRIX_H

typedef enum HookRiskLevel {
    HOOK_RISK_LOW = 0,
    HOOK_RISK_MEDIUM = 1,
    HOOK_RISK_HIGH = 2
} HookRiskLevel;

typedef struct LiveAreaHookMatrixEntry {
    const char *name;
    const char *category;
    HookRiskLevel risk;
    int firmware_checked;
    int reversible;
    int isolated;
    int safe;
} LiveAreaHookMatrixEntry;

int livearea_hook_matrix_init(LiveAreaHookMatrixEntry *entry);
int livearea_hook_matrix_is_allowed(const LiveAreaHookMatrixEntry *entry);
int livearea_hook_matrix_set_candidate(LiveAreaHookMatrixEntry *entry,
                                     const char *name,
                                     const char *category,
                                     HookRiskLevel risk,
                                     int firmware_checked,
                                     int reversible,
                                     int isolated,
                                     int safe);

#endif // LIVEAREA_HOOK_MATRIX_H
