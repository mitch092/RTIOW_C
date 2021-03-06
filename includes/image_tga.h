#pragma once
#pragma warning(push, 0)
#include <stdint.h>
#include <stdbool.h>
#pragma warning(pop)

typedef struct{
  uint8_t* byte_array;
} image_tga;

extern size_t image_tga_size_bytes(uint16_t width, uint16_t height);
extern image_tga image_tga_create(uint16_t width, uint16_t height);
extern uint16_t image_tga_width(const image_tga image);
extern uint16_t image_tga_height(const image_tga image);
extern void image_tga_set_pixel(image_tga image, uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);
extern void image_tga_set_all(image_tga image, uint8_t r, uint8_t g, uint8_t b);
extern bool image_tga_write_file(image_tga image, const char* filename);
extern void image_tga_destroy(image_tga image);
