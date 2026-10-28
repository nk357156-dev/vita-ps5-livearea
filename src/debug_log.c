#include "debug_log.h"

#include <stdio.h>

static int g_debug_enabled = 0;

void debug_log_init(void)
{
    g_debug_enabled = 1;
}

void debug_log_set_enabled(int enabled)
{
    g_debug_enabled = enabled;
}

void debug_log_print(const char *tag, const char *message)
{
    if (!g_debug_enabled)
        return;

    if (tag == NULL || message == NULL)
        return;

    printf("[%s] %s\n", tag, message);
}
