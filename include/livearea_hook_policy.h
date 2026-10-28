#ifndef LIVEAREA_HOOK_POLICY_H
#define LIVEAREA_HOOK_POLICY_H

typedef enum HookPolicyState {
    HOOK_POLICY_BLOCKED = 0,
    HOOK_POLICY_REVIEW = 1,
    HOOK_POLICY_ALLOWED = 2
} HookPolicyState;

typedef struct LiveAreaHookPolicy {
    const char *name;
    const char *category;
    int risk;
    int firmware_checked;
    int reversible;
    int isolated;
    int safe;
    HookPolicyState state;
} LiveAreaHookPolicy;

int livearea_hook_policy_init(LiveAreaHookPolicy *policy, const char *name, const char *category);
int livearea_hook_policy_evaluate(LiveAreaHookPolicy *policy);
int livearea_hook_policy_allow(LiveAreaHookPolicy *policy);
int livearea_hook_policy_block(LiveAreaHookPolicy *policy);

#endif // LIVEAREA_HOOK_POLICY_H
