#pragma warning(push, 0)
#include <stdlib.h>
#pragma warning(pop)

#include "image_tga.h"
#define HEADER_SIZE 18

struct image_tga{
  uint8_t* byte_array;
};

image_tga* image_tga_create(uint16_t width, uint16_t height) {
    /*
  image_tga image;
  // Using calloc to zero out the entire image. So the pixels will all be black by default.
  // And most of the header is zero, except for a few bytes.
  image.byte_array = calloc((HEADER_SIZE + (3 * width * height)), sizeof(uint8_t));

  // Set the data type code to uncompressed RGB.
  image.byte_array[2] = 2;

  // Split the width and height into bytes.
  // Casting from 16 bits unsigned to 8 bits *should* chop off the high byte and keep the low byte.
  image.byte_array[12] = (uint8_t)(width);
  // Bit shifting right 8 bits, then casting *should* return just the high byte.
  image.byte_array[13] = (uint8_t)(width >> 8);
  image.byte_array[14] = (uint8_t)(height);
  image.byte_array[15] = (uint8_t)(height >> 8);

  // Set the bits per pixel to 24.
  image.byte_array[16] = 24;

  return &image;*/




  
  // Using calloc to zero out the entire image. So the pixels will all be black by default.
  // And most of the header is zero, except for a few bytes.
  uint8_t* byte_array = calloc((HEADER_SIZE + (3 * width * height)), sizeof(uint8_t));

  // Set the data type code to uncompressed RGB.
  byte_array[2] = 2;

  // Split the width and height into bytes.
  // Casting from 16 bits unsigned to 8 bits *should* chop off the high byte and keep the low byte.
  byte_array[12] = (uint8_t)(width);
  // Bit shifting right 8 bits, then casting *should* return just the high byte.
  byte_array[13] = (uint8_t)(width >> 8);
  byte_array[14] = (uint8_t)(height);
  byte_array[15] = (uint8_t)(height >> 8);

  // Set the bits per pixel to 24.
  byte_array[16] = 24;

  return byte_array;
}

uint16_t image_tga_width(const image_tga* const image) {
  return ((uint16_t)(image->byte_array[13]) << 8) | ((uint16_t)(image->byte_array[12]));
}

uint16_t image_tga_height(const image_tga* const image) {
  return ((uint16_t)(image->byte_array[15]) << 8) | ((uint16_t)(image->byte_array[14]));
}

void image_tga_set_pixel(image_tga* image, uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b) {
  const size_t pixel_offset = (HEADER_SIZE + x + y * image_tga_width(image));
  image->byte_array[pixel_offset] = b;
  image->byte_array[pixel_offset + 1] = g;
  image->byte_array[pixel_offset + 2] = r;
  return;
}

//void image_tga_write_file(image_tga* image, const char* filename){}

void image_tga_destroy(image_tga* image) {
  free(image->byte_array);
  image->byte_array = NULL;
  return;
}
