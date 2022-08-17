#pragma warning(push, 0)
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#pragma warning(pop)

#include "progress.h"

void display_progress_bar(double percent) {
  assert(0 <= percent);

  const uint8_t barWidth = 70;
  fprintf_s(stderr, "[");
  uint8_t pos = (uint8_t)((double)barWidth * percent);

  for (uint8_t i = 0; i != barWidth; ++i) {
    if (i < pos) {
      fprintf_s(stderr, "=");
    } else if (i == pos) {
      fprintf_s(stderr, ">");
    } else {
      fprintf_s(stderr, " ");
    }
  }

  fprintf_s(stderr, "] %u%%\r", (uint8_t)(percent * 100.0));
  fflush(stderr);
  if (1.0 <= percent) {
    fprintf_s(stderr, "\n");
  }

  return;
}
