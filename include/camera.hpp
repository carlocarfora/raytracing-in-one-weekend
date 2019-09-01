//
// Created by carlo on 24/07/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_CAMERA_HPP
#define RAYTRACING_IN_ONE_WEEKEND_CAMERA_HPP

#include "../include/ray.hpp"

namespace cc {
    vec3 random_in_unit_disk();

    class camera {
    public:
        camera(vec3 lookFrom, vec3 lookAt, vec3 vUp, float vFov, float aspect, float aperture, float focus_dist);
        ray get_ray(float s, float t);

        vec3 origin;
        vec3 lower_left_corner;
        vec3 horizontal;
        vec3 vertical;
        vec3 u, v, w;
        float lens_radius;
    };
}

#endif //RAYTRACING_IN_ONE_WEEKEND_CAMERA_HPP
