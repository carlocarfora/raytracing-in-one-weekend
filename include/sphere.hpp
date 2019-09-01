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
            sphere(vec3 cen, float r, material *m) : center(cen), radius(r), mat_ptr(m) {};

            virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

            // default member variables
            vec3 center;
            float radius;
            material *mat_ptr;
    };

}

#endif //RAYTRACING_IN_ONE_WEEKEND_SPHERE_HPP
