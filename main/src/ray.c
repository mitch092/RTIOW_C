#include "ray.h"

ray make_ray(const point3 origin, const point3 direction) {
  ray r = {.origin = origin, .dir = direction};
  return r;
}

point3 ray_at(const ray r, real t) { return vec3_add_vec3(r.origin, vec3_mult_scalar(r.dir, t)); }
