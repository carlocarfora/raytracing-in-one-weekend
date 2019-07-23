//
// Created by carlo on 18/07/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_SPHERE_HPP
#define RAYTRACING_IN_ONE_WEEKEND_SPHERE_HPP

#include "../include/hitable.hpp"

namespace cc {
    class sphere: public hitable {
        public:
            // default constructor
            sphere() = default;

            // initialisation list
            sphere(cc::vec3 cen, float r) : center(cen), radius(r) {};

            virtual bool hit(const cc::ray& r, float t_min, float t_max, cc::hit_record& rec) const;

            // default member variables
            cc::vec3 center;
            float radius;
    };

}

#endif //RAYTRACING_IN_ONE_WEEKEND_SPHERE_HPP
