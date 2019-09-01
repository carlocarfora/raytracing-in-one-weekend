#include <iostream>
#include <fstream>
#include "../include/vec3.hpp"
#include "../include/material.hpp"
#include "../include/ray.hpp"
#include "../include/sphere.hpp"
#include "../include/hitablelist.hpp"
#include "../include/camera.hpp"


cc::vec3 colour(const cc::ray& r, cc::hitable *world, int depth) {
    cc::hit_record rec;
    if (world->hit(r, 0.001, MAXFLOAT,rec)) {
        cc::ray scattered;
        cc::vec3 attenuation;
        if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
            return attenuation * colour(scattered, world, depth+1);
        } else {
            return cc::vec3(0, 0, 0);
        }
    }
    else {
        cc::vec3 unit_direction = unit_vector(r.direction());
        float t = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - t) * cc::vec3(1.0, 1.0, 1.0) + t * cc::vec3(0.5, 0.7, 1.0);
    }
}

cc::hitable *random_scene() {
    int n = 500;
    cc::hitable **list = new cc::hitable*[n+1];
    list[0] = new cc::sphere(cc::vec3(0,-1000,0), 1000, new cc::lambertian(cc::vec3(0.5,0.5,0.5)));
    int i = 1;
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            float choose_mat = drand48();
            cc::vec3 center(a+0.9*drand48(),0.2,b+0.9*drand48());
            if ((center - cc::vec3(4,0.2,0)).length() > 0.9) {
                if (choose_mat < 0.8) {
                    list[i++] = new cc::sphere(center, 0.2,
                                new cc::lambertian(cc::vec3(drand48(),drand48(),drand48())));
                }
                else if (choose_mat < 0.95) {
                    list[i++] = new cc::sphere(center, 0.2,
                                new cc::metal(cc::vec3(0.5*(1 + drand48()),0.5*(1 + drand48()),0.5*(1 + drand48())),0.5*drand48()));
                }
                else {
                    list[i++] = new cc::sphere(center, 0.2, new cc::dielectric(1.5));
                }
            }
        }
    }

    list[i++] = new cc::sphere(cc::vec3(0,1,0), 1.0, new cc::dielectric(1.5));
    list[i++] = new cc::sphere(cc::vec3(-4,1,0), 1.0, new cc::lambertian(cc::vec3(0.4,0.2,0.1)));
    list[i++] = new cc::sphere(cc::vec3(4,1,0), 1.0, new cc::metal(cc::vec3(0.7,0.6,0.5), 0.0));

    return new cc::hitablelist(list,i);
}

int main() {
    std::ofstream ppm;
    ppm.open("image.ppm");

    int nx = 600;
    int ny = 300;
    int ns = 20;
    ppm << "P3\n" << nx << " " << ny << "\n255\n";
    cc::hitable *world = random_scene();
    cc::vec3 lookFrom(13,2,3);
    cc::vec3 lookAt(0,0,0);
    float dist_to_focus = (lookFrom-lookAt).length();
    float aperture = 0.2;
    cc::camera cam(lookFrom, lookAt, cc::vec3(0,1,0), 20, float(nx)/float(ny), aperture, dist_to_focus);
    for(auto j = (ny - 1); j >= 0; j--) {
        for(auto i = 0; i < nx; i++) {
            cc::vec3 col(0,0,0);
            for (auto s = 0; s < ns; s++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                cc::ray r = cam.get_ray(u, v);
                cc::vec3 p = r.point_at_parameter(2.0);
                col += colour(r, world, 0);

            }
            col /= float(ns);
            col = cc::vec3(sqrt(col[0]), sqrt(col[1]), sqrt(col[2]));
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            ppm << ir << " " << ig << " " << ib << "\n";
        }
    }


}