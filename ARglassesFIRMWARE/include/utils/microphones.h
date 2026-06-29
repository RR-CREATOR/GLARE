#pragma once
#include <stddef.h>
#include <stdint.h>

void microphones_init(void);
size_t microphones_read(int16_t *out, size_t samples); // mono PCM from mic1
