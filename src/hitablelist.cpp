//
// Created by carlo on 23/07/19.
//

#include "../include/hitablelist.hpp"

namespace cc {
    bool hitablelist::hit(const ray& r, float tmin, float tmax, hit_record& rec) const {
        hit_record temp_rec;
        bool hit_anything = false;
        double closest_so_far = t_max;
        for (int i = 0; i < list_size; i++) {
            if (list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        }
        return hit_anything;
    }
}
