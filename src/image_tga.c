#pragma warning(push, 0)
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(pop)

#include "image_tga.h"
#define HEADER_SIZE 18
#define FOOTER_SIZE 26

size_t image_tga_size_bytes(uint16_t width, uint16_t height) { return (HEADER_SIZE + (3 * width * height) + FOOTER_SIZE); }

image_tga image_tga_create(uint16_t width, uint16_t height) {
  assert(0 < width);
  assert(0 < height);

  image_tga image;
  // Using calloc to zero out the entire image. So the pixels will all be black by default.
  // And most of the header is zero, except for a few bytes.
  image.byte_array = calloc(image_tga_size_bytes(width, height), sizeof(uint8_t));
  assert(image.byte_array != NULL);

  // Set the data type code to uncompressed RGB.
  image.byte_array[2] = 2;

  // Tells the header that the y coordinate is inverted.
  image.byte_array[10] = (uint8_t)(height);
  image.byte_array[11] = (uint8_t)((height) >> 8);

  // Split the 16 bit width and height into a pair of 8 bit bytes.
  image.byte_array[12] = (uint8_t)(width);
  image.byte_array[13] = (uint8_t)(width >> 8);
  image.byte_array[14] = (uint8_t)(height);
  image.byte_array[15] = (uint8_t)(height >> 8);

  // Set the bits per pixel to 24.
  image.byte_array[16] = 24;

  // This is for setting the origin point.
  // 0x00 is the lower left corner of the screen (is set that way by calloc), 0x20 sets it to be the upper left.
  // image.byte_array[17] = 0x20;

  // Inserting the secret message at the end of the file (visible in the Gimp reference file viewed in a hex editor).
  const char msg[] = "TRUEVISION-XFILE.";
  size_t footer_msg_start = image_tga_size_bytes(width, height) - FOOTER_SIZE + 8;
  for (size_t ch = 0; ch != sizeof(msg); ++ch) {
    image.byte_array[footer_msg_start + ch] = (uint8_t)(msg[ch]);
  }

  assert(width == image_tga_width(image));
  assert(height == image_tga_height(image));

  return image;
}

uint16_t image_tga_width(const image_tga image) {
  assert(image.byte_array != NULL);
  return ((uint16_t)(image.byte_array[13]) << 8) | (uint16_t)(image.byte_array[12]);
}

uint16_t image_tga_height(const image_tga image) {
  assert(image.byte_array != NULL);
  return ((uint16_t)(image.byte_array[15]) << 8) | (uint16_t)(image.byte_array[14]);
}

void image_tga_set_pixel(image_tga image, uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b) {
  // Flip the y axis, so that the upper left corner is the origin point, and not the lower left.
  // Not needed, because there is a single byte in the header that controls this.
  // y = image_tga_height(image) - y - 1;

  assert(image.byte_array != NULL);
  assert(0 <= x);
  assert(0 <= y);
  assert(x < image_tga_width(image));
  assert(y < image_tga_height(image));

  const size_t pixel_offset = (HEADER_SIZE + (x + y * image_tga_width(image)) * 3);

  assert(pixel_offset < image_tga_size_bytes(image_tga_width(image), image_tga_height(image)));
  image.byte_array[pixel_offset] = b;

  assert((pixel_offset + 1) < image_tga_size_bytes(image_tga_width(image), image_tga_height(image)));
  image.byte_array[pixel_offset + 1] = g;

  assert((pixel_offset + 2) < image_tga_size_bytes(image_tga_width(image), image_tga_height(image)));
  image.byte_array[pixel_offset + 2] = r;

  return;
}

void image_tga_set_all(image_tga image, uint8_t r, uint8_t g, uint8_t b) {
  assert(image.byte_array != NULL);

  uint16_t height = image_tga_height(image);
  uint16_t width = image_tga_width(image);
  for (uint16_t y = 0; y != height; ++y) {
    for (uint16_t x = 0; x != width; ++x) {
      image_tga_set_pixel(image, x, y, r, g, b);
    }
  }

  return;
}

bool image_tga_write_file(image_tga image, const char* filename) {
  assert(image.byte_array != NULL);

  FILE* file;
  errno_t err;
  err = fopen_s(&file, filename, "wb");
  if (err != 0) {
    fprintf_s(stderr, "Cannot open file '%s'\n", filename);
    return false;
  }

  uint16_t width = image_tga_width(image);
  uint16_t height = image_tga_height(image);
  size_t byte_count = image_tga_size_bytes(width, height);
  fwrite((void*)(image.byte_array), sizeof(uint8_t), byte_count, file);

  fclose(file);
  return true;
}

void image_tga_destroy(image_tga image) {
  assert(image.byte_array != NULL);
  free(image.byte_array);
  image.byte_array = NULL;
  return;
}
