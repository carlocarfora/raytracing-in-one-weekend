#include <iostream>
#include <fstream>
#include "../include/vec3.hpp"
#include "../include/ray.hpp"

float hit_sphere(const cc::vec3& center, float radius, const cc::ray& r) {
    cc::vec3 oc = r.origin() - center;
    float a = cc::dot(r.direction(), r.direction());
    float b = 2.0 * cc::dot(oc, r.direction());
    float c = cc::dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
}

cc::vec3 colour(const cc::ray& r) {
    float t = hit_sphere(cc::vec3(0,0,-1), 0.5, r);
    if (t > 0.0) {
        cc::vec3 N = cc::unit_vector(r.point_at_parameter(t) - cc::vec3(0, 0, -1));
        return 0.5 * cc::vec3(N.x() + 1, N.y() + 1, N.z() + 1);
    }
    cc::vec3 unit_direction = cc::unit_vector(r.direction());
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*cc::vec3(1.0,1.0,1.0) + t*cc::vec3(0.5,0.7,1.0);
}

int main() {
    std::ofstream ppm;
    ppm.open("image.ppm");

    int nx = 200;
    int ny = 100;
    ppm << "P3\n" << nx << " " << ny << "\n255\n";

    cc::vec3 lower_left_corner(-2.0, -1.0, -1.0);
    cc::vec3 horizontal(4.0, 0.0, 0.0);
    cc::vec3 vertical(0.0, 2.0, 0.0);
    cc::vec3 origin(0.0, 0.0, 0.0);

    for(auto j = (ny - 1); j >= 0; j--) {
        for(int i = 0; i < nx; i++) {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            cc::ray r(origin, lower_left_corner +u*horizontal + v*vertical);
            cc::vec3 col = colour(r);
            int ir = int(255.99 * col[0]);
            int ig = int(255.99 * col[1]);
            int ib = int(255.99 * col[2]);

            ppm << ir << " " << ig << " " << ib << "\n";
        }
    }


}