//
// Created by carlo on 24/04/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_RAY_HPP
#define RAYTRACING_IN_ONE_WEEKEND_RAY_HPP

#include "../include/vec3.hpp"

namespace cc {
    struct ray {
        // default constructor
        ray() = default;

        // parameter constructor
        ray(const cc::vec3& a, const vec3& b) {
            A = a;
            B = b;
        };

        // member methods
        vec3 origin() const;
        vec3 direction() const;
        vec3 point_at_parameter(float t) const;

        // default member variables
        vec3 A;
        vec3 B;

    };
}

#endif //RAYTRACING_IN_ONE_WEEKEND_RAY_HPP
