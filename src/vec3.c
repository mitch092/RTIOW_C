#pragma warning(push, 0)
#include "math.h"
#pragma warning(pop)

#include "vec3.h"

pixel color_to_pixel(const color c) {
  pixel pxl = {.r = (uint8_t)(c.x * 255.999), .g = (uint8_t)(c.y * 255.999), .b = (uint8_t)(c.z * 255.999)};
  return pxl;
}

vec3 vec3_from_reals(const real x, const real y, const real z) {
  vec3 v = {.x = x, .y = y, .z = z};
  return v;
}

real vec3_dot_vec3(const vec3 v1, const vec3 v2) { return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z)); }

vec3 vec3_cross_vec3(const vec3 v1, const vec3 v2) {
  return vec3_from_reals(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
}

real vec3_length_squared(const vec3 v) { return v.x * v.x + v.y * v.y + v.y * v.z; }

real vec3_length(const vec3 v) { return sqrt(vec3_length_squared(v)); }

vec3 vec3_origin(void) { return vec3_from_reals(0, 0, 0); };

vec3 vec3_mult_scalar(const vec3 v, const real r) { return vec3_from_reals(v.x * r, v.y * r, v.z * r); }

vec3 vec3_div_scalar(const vec3 v, const real r) { return vec3_mult_scalar(v, 1 / r); }

vec3 vec3_negate(const vec3 v) { return vec3_mult_scalar(v, -1); }

vec3 vec3_add_vec3(const vec3 v1, const vec3 v2) { return vec3_from_reals(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }

vec3 vec3_sub_vec3(const vec3 v1, const vec3 v2) { return vec3_from_reals(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }

vec3 vec3_mult_vec3(const vec3 v1, const vec3 v2) { return vec3_from_reals(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z); }

vec3 vec3_unit_vector(const vec3 v) { return vec3_div_scalar(v, vec3_length(v)); }

vec3 vec3_dir_from_point3(const point3 to, const point3 from) { return vec3_unit_vector(vec3_sub_vec3(to, from)); }
