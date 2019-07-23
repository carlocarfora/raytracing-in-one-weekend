//
// Created by carlo on 24/04/19.
//

#include "../include/ray.hpp"

namespace cc {
    vec3 ray::origin() const {
        return A;
    }

    vec3 ray::direction() const {
        return B;
    }

    vec3 ray::point_at_parameter(float t) const {
        return A + t*B;
    }
}
