#include "livearea_hook_policy.h"

#include <string.h>

int livearea_hook_policy_init(LiveAreaHookPolicy *policy, const char *name, const char *category)
{
    if (policy == NULL)
        return -1;

    memset(policy, 0, sizeof(*policy));
    policy->name = name;
    policy->category = category;
    policy->risk = 2;
    policy->firmware_checked = 0;
    policy->reversible = 0;
    policy->isolated = 0;
    policy->safe = 0;
    policy->state = HOOK_POLICY_BLOCKED;
    return 0;
}

int livearea_hook_policy_evaluate(LiveAreaHookPolicy *policy)
{
    if (policy == NULL)
        return -1;

    if (policy->risk == 2)
        return -1;

    if (policy->firmware_checked == 0)
        return -1;

    if (policy->reversible == 0)
        return -1;

    if (policy->isolated == 0)
        return -1;

    if (policy->safe == 0)
        return -1;

    policy->state = HOOK_POLICY_ALLOWED;
    return 0;
}

int livearea_hook_policy_allow(LiveAreaHookPolicy *policy)
{
    if (policy == NULL)
        return -1;

    policy->state = HOOK_POLICY_ALLOWED;
    return 0;
}

int livearea_hook_policy_block(LiveAreaHookPolicy *policy)
{
    if (policy == NULL)
        return -1;

    policy->state = HOOK_POLICY_BLOCKED;
    return 0;
}
