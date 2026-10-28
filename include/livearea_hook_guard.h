#ifndef LIVEAREA_HOOK_GUARD_H
#define LIVEAREA_HOOK_GUARD_H

typedef enum HookRiskLevel {
    HOOK_RISK_LOW = 0,
    HOOK_RISK_MEDIUM = 1,
    HOOK_RISK_HIGH = 2
} HookRiskLevel;

typedef struct LiveAreaHookCandidate {
    const char *name;
    const char *category;
    HookRiskLevel risk;
    int firmware_checked;
    int reversible;
    int isolated;
    int safe;
} LiveAreaHookCandidate;

int livearea_hook_guard_init(LiveAreaHookCandidate *candidate);
int livearea_hook_guard_evaluate(const LiveAreaHookCandidate *candidate);
int livearea_hook_guard_is_safe(const LiveAreaHookCandidate *candidate);

#endif // LIVEAREA_HOOK_GUARD_H
