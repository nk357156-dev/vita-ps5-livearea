#ifndef DEBUG_LOG_H
#define DEBUG_LOG_H

#include <stddef.h>

void debug_log_init(void);
void debug_log_set_enabled(int enabled);
void debug_log_print(const char *tag, const char *message);

#endif // DEBUG_LOG_H
