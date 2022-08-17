#pragma once
#pragma warning(push, 0)
#include <stdint.h>
#include <stdbool.h>
#pragma warning(pop)

typedef struct {
  bool exists;
  uint16_t val;
} maybe_uint16;

maybe_uint16 str_to_uint16(const char *str);
