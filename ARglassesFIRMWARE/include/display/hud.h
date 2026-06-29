#pragma once
#include <stddef.h>

void hud_init(void);
void hud_show(const char *text);             // null-terminated line
void hud_show_n(const char *text, size_t n); // length-bounded (ws frames aren't terminated)
