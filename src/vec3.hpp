//
// Created by carlo on 11/11/18.
//

#ifndef RAYTRACING_IN_ONE_WEEKEND_VEC3_HPP
#define RAYTRACING_IN_ONE_WEEKEND_VEC3_HPP

#include <math.h>
#include <array>

namespace cc{

    struct vec3 {
        // member variables
        std::array<float, 3> e {};

        // default constructor
        vec3() {
            e = {0,0,0};
        }

        // parameter constructor
        vec3(float e0, float e1, float e2) {
            e[0] = e0;
            e[1] = e1;
            e[2] = e2;
        }

        // member methods
        float x() const;
        float y() const;
        float z() const;
        float r() const;
        float g() const;
        float b() const;

        // operator overloads
        const vec3& operator+() const {
            return *this;
        }

        vec3 operator-() const {
            return vec3{-e[0], -e[1],-e[2]};
        }

        float operator[](int i) const {
            return e[i];
        }

        float& operator[](int i) {
            return e[i];
        }

        vec3& operator+=(const vec3& v2);
        vec3& operator-=(const vec3& v2);
        vec3& operator*=(const vec3& v2);
        vec3& operator/=(const vec3& v2);
        vec3& operator*=(const float t);
        vec3& operator/=(const float t);

        float length() const {
            return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
        }

        float squared_length() const {
            return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
        }
    };

    std::istream& operator>>(std::istream& is, vec3& t);
    std::ostream& operator<<(std::ostream& os, vec3& t);

}

#endif //RAYTRACING_IN_ONE_WEEKEND_VEC3_HPP
