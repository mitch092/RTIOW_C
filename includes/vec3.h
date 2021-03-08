#pragma once
#pragma warning(push, 0)
#include <stdint.h>
#pragma warning(pop)

typedef double real;

typedef struct {
  real x;
  real y;
  real z;
} vec3, point3, color;

typedef struct {
  uint8_t r;
  uint8_t g;
  uint8_t b;
} pixel;

extern pixel color_to_pixel(const color c);
extern vec3 vec3_from_reals(const real x, const real y, const real z);
extern real vec3_dot_vec3(const vec3 v1, const vec3 v2);
extern vec3 vec3_cross_vec3(const vec3 v1, const vec3 v2);
extern real vec3_length_squared(const vec3 v);
extern real vec3_length(const vec3 v);
extern vec3 vec3_origin(void);
extern vec3 vec3_mult_scalar(const vec3 v, const real r);
extern vec3 vec3_div_scalar(const vec3 v, const real r);
extern vec3 vec3_negate(const vec3 v);
extern vec3 vec3_add_vec3(const vec3 v1, const vec3 v2);
extern vec3 vec3_sub_vec3(const vec3 v1, const vec3 v2);
extern vec3 vec3_mult_vec3(const vec3 v1, const vec3 v2);
extern vec3 vec3_unit_vector(const vec3 v);
extern vec3 vec3_dir_from_point3(const point3 to, const point3 from);
