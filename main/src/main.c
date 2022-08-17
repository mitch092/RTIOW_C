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

  uint16_t width = 0;
  if (str_to_uint16(argv[1], &width) == false) {
    fprintf_s(stderr, "%s is not a proper positive integral width.\n", argv[1]);
    return EXIT_FAILURE;
  }

  uint16_t height = 0;
  if (str_to_uint16(argv[2], &height) == false) {
    fprintf_s(stderr, "%s is not a proper positive integral height.\n", argv[2]);
    return EXIT_FAILURE;
  }

  image_tga image = image_tga_create(width, height);

  fprintf_s(stderr, "Scanline percent:\n");
  for (uint16_t y = 0; y != height; ++y) {
    display_progress_bar((double)(y + 1) / (double)(height));
    for (uint16_t x = 0; x != width; ++x) {
      pixel p = color_to_pixel(vec3_from_reals((double)(x) / (double)(width - 1), (double)(y) / (double)(height - 1), 0.25));
      image_tga_set(image, x, y, p.r, p.g, p.b);
    }
  }

  if (image_tga_write_file(image, argv[3]) == false) {
    return EXIT_FAILURE;
  }
  image_tga_destroy(image);
  return EXIT_SUCCESS;
}
