//
// Created by carlo on 18/07/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_HITABLE_HPP
#define RAYTRACING_IN_ONE_WEEKEND_HITABLE_HPP

#include "ray.hpp"

namespace cc {
    class material;

    struct hit_record {
        float t;
        vec3 p;
        vec3 normal;
        material *mat_ptr;
    };

    class hitable {
        public:
            virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
    };
}


#endif //RAYTRACING_IN_ONE_WEEKEND_HITABLE_HPP
