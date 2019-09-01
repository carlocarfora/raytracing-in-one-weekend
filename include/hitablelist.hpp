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
            hitablelist()  = default;

            hitablelist(hitable **l, int n) {list = l; list_size = n; }
            virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
            hitable **list;
            int list_size;
    };
}

#endif //RAYTRACING_IN_ONE_WEEKEND_HITABLELIST_HPP
