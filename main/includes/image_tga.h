#pragma once
#pragma warning(push, 0)
#include <stdbool.h>
#include <stdint.h>
#pragma warning(pop)

typedef struct {
  uint8_t* byte_array;
} image_tga;

size_t image_tga_size_bytes(const uint16_t width, const uint16_t height);
image_tga image_tga_create(const uint16_t width, const uint16_t height);
uint16_t image_tga_width(const image_tga image);
uint16_t image_tga_height(const image_tga image);
void image_tga_set(image_tga image, const uint16_t x, const uint16_t y, const uint8_t r, const uint8_t g,
                          const uint8_t b);
void image_tga_set_all(image_tga image, const uint8_t r, const uint8_t g, const uint8_t b);
bool image_tga_write_file(const image_tga image, const char* filename);
void image_tga_destroy(image_tga image);
