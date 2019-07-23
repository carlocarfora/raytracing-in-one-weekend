//
// Created by carlo on 18/07/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_HITABLE_HPP
#define RAYTRACING_IN_ONE_WEEKEND_HITABLE_HPP

#include "ray.hpp"

namespace cc {
    struct hit_record {
        float t;
        cc::vec3 p;
        cc::vec3 normal;
    };

    class hitable {
        public:
            virtual bool hit(const cc::ray& r, float t_min, float t_max, hit_record& rec) const = 0;
    };
}


#endif //RAYTRACING_IN_ONE_WEEKEND_HITABLE_HPP
