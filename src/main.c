#pragma warning(push, 0)
#include <stdio.h>
#include <stdlib.h>
#pragma warning(pop)

#include "image_tga.h"
#include "params.h"

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
  image_tga_set_all(image, 255, 255, 255);

  if (image_tga_write_file(image, argv[3]) == false) {
    return EXIT_FAILURE;
  }

  image_tga_destroy(image);

  return EXIT_SUCCESS;
}
