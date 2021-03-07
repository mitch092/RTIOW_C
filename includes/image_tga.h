#pragma once
#pragma warning(push, 0)
#include <stdbool.h>
#include <stdint.h>
#pragma warning(pop)

typedef struct {
  uint8_t* byte_array;
} image_tga;

extern size_t image_tga_size_bytes(const uint16_t width, const uint16_t height);
extern image_tga image_tga_create(const uint16_t width, const uint16_t height);
extern uint16_t image_tga_width(const image_tga image);
extern uint16_t image_tga_height(const image_tga image);
extern void image_tga_set(image_tga image, const uint16_t x, const uint16_t y, const uint8_t r, const uint8_t g,
                          const uint8_t b);
extern void image_tga_set_all(image_tga image, const uint8_t r, const uint8_t g, const uint8_t b);
extern bool image_tga_write_file(const image_tga image, const char* filename);
extern void image_tga_destroy(image_tga image);
