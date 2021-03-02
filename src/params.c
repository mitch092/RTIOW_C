#pragma warning(push, 0)
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#pragma warning(pop)

#include "params.h"

bool str_to_uint16(const char *str, uint16_t *res) {
  char *end;
  errno = 0;
  long val = strtol(str, &end, 10);
  if (errno || end == str || *end != '\0' || val < 0 || val >= 0x10000) {
    return false;
  }
  *res = (uint16_t)val;
  return true;
}
