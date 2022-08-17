#pragma warning(push, 0)
#include <stdio.h>
#include <stdlib.h>
#pragma warning(pop)

#include "image_tga.h"
#include "params.h"
#include "progress.h"
#include "vec3.h"

int main(int argc, const char* argv[]) {
  if (argc != 4) {
    fprintf_s(stderr, "Usage: width height name\n");
    return EXIT_FAILURE;
  }

  maybe_uint16 width = str_to_uint16(argv[1]);
  if (!width.exists) {
    fprintf_s(stderr, "%s is not a proper positive integral width.\n", argv[1]);
    return EXIT_FAILURE;
  }

  maybe_uint16 height = str_to_uint16(argv[2]);
  if (!height.exists) {
    fprintf_s(stderr, "%s is not a proper positive integral height.\n", argv[2]);
    return EXIT_FAILURE;
  }

  image_tga image = image_tga_create(width.val, height.val);

  fprintf_s(stderr, "Scanline percent:\n");
  for (uint16_t y = 0; y != height.val; ++y) {
    display_progress_bar((double)(y + 1) / (double)(height.val));
    for (uint16_t x = 0; x != width.val; ++x) {
      pixel p = color_to_pixel(vec3_from_reals((double)(x) / (double)(width.val - 1), (double)(y) / (double)(height.val - 1), 0.25));
      image_tga_set(image, x, y, p.r, p.g, p.b);
    }
  }

  if (image_tga_write_file(image, argv[3]) == false) {
    return EXIT_FAILURE;
  }
  image_tga_destroy(image);
  return EXIT_SUCCESS;
}
