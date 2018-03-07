#pragma once

#include "stdint.h"
#include "stddef.h"

int printf(const char* restrict format, ...);
uint8_t default_console_color;
void itoa(unsigned i,char* buf, unsigned base);
