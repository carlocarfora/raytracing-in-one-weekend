//
// Created by carlo on 18/07/19.
//

#include "../include/sphere.hpp"

namespace cc {
    bool sphere::hit(const cc::ray& r, float t_min, float t_max, cc::hit_record& rec) const {
        cc::vec3 oc = r.origin() - center;
        float a = dot(r.direction(), r.direction());
        float b = dot(oc, r.direction());
        float c = dot(oc, oc) - radius*radius;
        float discriminant = b*b - a*c;

        if (discriminant > 0) {
            float temp = (-b - sqrt(b*b - a*c))/a;
            if (temp < t_max && temp > t_min) {
                rec.t = temp;
                rec.p = r.point_at_parameter(rec.t);
                rec.normal = (rec.p - center) / radius;
                return true;
            }
            temp = (-b + sqrt(b*b - a*c))/a;
            if (temp < t_max && temp > t_min) {
                rec.t = temp;
                rec.p = r.point_at_parameter(rec.t);
                rec.normal = (rec.p-center) / radius;
                return true;
            }
        }
        return false;
    }
}