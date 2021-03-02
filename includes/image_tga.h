#pragma once
#pragma warning(push, 0)
#include <stdint.h>
#pragma warning(pop)

typedef struct image_tga image_tga;

extern image_tga* image_tga_create(uint16_t width, uint16_t height);
extern uint16_t image_tga_width(const image_tga* const image);
extern uint16_t image_tga_height(const image_tga* const image);
extern void image_tga_set_pixel(image_tga* image, uint16_t x, uint16_t y, uint8_t r, uint8_t g, uint8_t b);
//extern void image_tga_write_file(image_tga* image, const char* filename);
extern void image_tga_destroy(image_tga* image);
