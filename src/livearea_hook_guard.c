#include "livearea_hook_guard.h"

#include <string.h>

int livearea_hook_guard_init(LiveAreaHookCandidate *candidate)
{
    if (candidate == NULL)
        return -1;

    memset(candidate, 0, sizeof(*candidate));
    candidate->name = "unnamed";
    candidate->category = "unknown";
    candidate->risk = HOOK_RISK_HIGH;
    candidate->firmware_checked = 0;
    candidate->reversible = 0;
    candidate->isolated = 0;
    candidate->safe = 0;
    return 0;
}

int livearea_hook_guard_evaluate(const LiveAreaHookCandidate *candidate)
{
    if (candidate == NULL)
        return -1;

    if (candidate->risk == HOOK_RISK_HIGH)
        return -1;

    if (candidate->firmware_checked == 0)
        return -1;

    if (candidate->reversible == 0)
        return -1;

    if (candidate->isolated == 0)
        return -1;

    return 0;
}

int livearea_hook_guard_is_safe(const LiveAreaHookCandidate *candidate)
{
    if (livearea_hook_guard_evaluate(candidate) != 0)
        return 0;

    if (candidate->risk == HOOK_RISK_LOW || candidate->risk == HOOK_RISK_MEDIUM)
        return 1;

    return 0;
}
