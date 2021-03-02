#pragma warning(push, 0)
#include <stdio.h>
#include <stdlib.h>
#pragma warning(pop)

#include "image_tga.h"
#include "params.h"

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    printf("Usage: width height\n");
    return EXIT_FAILURE;
  }

  uint16_t width = 0;
  if (str_to_uint16(argv[1], &width) == false) {
    printf("%s is not a proper positive integral width.\n", argv[1]);
    return EXIT_FAILURE;
  }

  uint16_t height = 0;
  if (str_to_uint16(argv[2], &height) == false) {
    printf("%s is not a proper positive integral height.\n", argv[2]);
    return EXIT_FAILURE;
  }

  printf("The input width is %u and the height is %u.\n", width, height);
  image_tga* image = image_tga_create(width, height);
  printf("The image width is %u and the height is %u.\n", image_tga_width(image), image_tga_height(image));

  return EXIT_SUCCESS;
}
