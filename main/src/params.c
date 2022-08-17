#pragma warning(push, 0)
#include <errno.h>
#include <inttypes.h>
#include <stdlib.h>
#pragma warning(pop)

#include "params.h"

maybe_uint16 str_to_uint16(const char *str) {
  char *end;
  errno = 0;
  long number = strtol(str, &end, 10);

  maybe_uint16 convertedNumber = {
    .exists = (errno || end == str || *end != '\0' || number < 0 || number >= 0x10000),
    .val = (uint16_t)number
  };

  return convertedNumber;
}
