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

pixel color_to_pixel(const color c);
vec3 vec3_from_reals(const real x, const real y, const real z);
real vec3_dot_vec3(const vec3 v1, const vec3 v2);
vec3 vec3_cross_vec3(const vec3 v1, const vec3 v2);
real vec3_length_squared(const vec3 v);
real vec3_length(const vec3 v);
vec3 vec3_origin(void);
vec3 vec3_mult_scalar(const vec3 v, const real r);
vec3 vec3_div_scalar(const vec3 v, const real r);
vec3 vec3_negate(const vec3 v);
vec3 vec3_add_vec3(const vec3 v1, const vec3 v2);
vec3 vec3_sub_vec3(const vec3 v1, const vec3 v2);
vec3 vec3_mult_vec3(const vec3 v1, const vec3 v2);
vec3 vec3_unit_vector(const vec3 v);
vec3 vec3_dir_from_point3(const point3 to, const point3 from);
