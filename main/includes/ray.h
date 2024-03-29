#pragma once

#include "vec3.h"

typedef struct {
  point3 origin;
  vec3 dir;
} ray;

ray make_ray(const point3 origin, const point3 direction);
point3 ray_at(const ray r, real t);
