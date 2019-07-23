//
// Created by carlo on 23/07/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_HITABLELIST_HPP
#define RAYTRACING_IN_ONE_WEEKEND_HITABLELIST_HPP

#include "../include/hitable.hpp"

namespace cc {
    class hitablelist: public hitable {
        public:
            // default constructor
            hitablelist() = default;

            hitablelist(hitable **1, int n) {
                list = 1;
                list_size = n;
            }
            virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
            hitable **list;
            int list_size;
    }
}

#endif //RAYTRACING_IN_ONE_WEEKEND_HITABLELIST_HPP
