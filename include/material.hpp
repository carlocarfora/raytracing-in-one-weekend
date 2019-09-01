//
// Created by carlo on 19/08/19.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_MATERIAL_HPP
#define RAYTRACING_IN_ONE_WEEKEND_MATERIAL_HPP


#include "ray.hpp"
#include "hitable.hpp"

namespace cc {

    class material {
    public:
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const = 0;
    };

    class lambertian : public material {
    public:
        // default constructor
        lambertian(const vec3& a) : albedo(a) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

        vec3 albedo;
    };

    class metal : public material {
    public:
        // default constructor
        metal(const vec3 a, float f) : albedo(a) {
            if (f < 1) {
                fuzz = f;
            }
            else {
                fuzz = 1;
            }
        }
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

        vec3 albedo;
        float fuzz;
    };

    class dielectric : public material {
    public:
        dielectric(float ri) : ref_idx(ri) {}
        virtual bool scatter(const ray& r_in, const hit_record& rec, vec3& attenuation, ray& scattered) const;

        float ref_idx;
    };

    vec3 random_in_unit_sphere();
    vec3 reflect(const vec3& v, const vec3& n);
    bool refract(const vec3& v, const vec3& n, float ni_over_nt, vec3& refracted);
    float schlick(float cosine, float ref_idx);
}


#endif //RAYTRACING_IN_ONE_WEEKEND_MATERIAL_HPP
