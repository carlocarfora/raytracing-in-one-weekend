//
// Created by carlo on 11/11/18.
//

#include <iostream>
#include "../include/vec3.hpp"


namespace cc {

    float vec3::x() const {
        return e[0];
    }

    float vec3::y() const {
        return e[1];
    }

    float vec3::z() const {
        return e[2];
    }

    float vec3::r() const {
        return e[0];
    }

    float vec3::g() const {
        return e[1];
    }

    float vec3::b() const {
        return e[2];
    }

    float vec3::length() const {
        return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    }

    float vec3::squared_length() const {
        return (e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
    }

    vec3& vec3::operator+=(const vec3& v1) {
        e[0] += v1.e[0];
        e[1] += v1.e[1];
        e[2] += v1.e[2];
        return *this;
    }

    vec3& vec3::operator-=(const vec3& v1) {
        e[0] -= v1.e[0];
        e[1] -= v1.e[1];
        e[2] -= v1.e[2];
        return *this;
    }

    vec3& vec3::operator*=(const vec3& v1) {
        e[0] *= v1.e[0];
        e[1] *= v1.e[1];
        e[2] *= v1.e[2];
        return *this;
    }

    vec3& vec3::operator/=(const vec3& v1) {
        e[0] /= v1.e[0];
        e[1] /= v1.e[1];
        e[2] /= v1.e[2];
        return *this;
    }

    vec3& vec3::operator*=(float t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    vec3& vec3::operator/=(float t) {
        float k = 1.0 / t;

        e[0] /= t;
        e[1] /= t;
        e[2] /= t;
        return *this;
    }

    std::istream& operator>>(std::istream& is, vec3& t) {
        is >> t.e[0] >> t.e[1] >> t.e[2];
        return is;
    }

    std::ostream& operator<<(std::ostream &os, vec3 &t) {
        os << t.e[0] << " " << t.e[1] << " " << t.e[2];
        return os;
    }

    bool operator==(const vec3& lhs, const vec3& rhs) {
        if (lhs.e[0] == rhs.e[0] &&
            lhs.e[1] == rhs.e[1] &&
            lhs.e[2] == rhs.e[2])
        {
            return true;
        } else {
            return false;
        }
    }

    vec3 operator+(const vec3& v1, const vec3& v2) {
        return vec3{v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]};
    }

    vec3 operator-(const vec3& v1, const vec3& v2) {
        return vec3{v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]};
    }

    vec3 operator*(const vec3& v1, const vec3& v2) {
        return vec3{v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]};
    }

    vec3 operator/(const vec3& v1, const vec3& v2) {
        return vec3{v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]};
    }

    vec3 operator*(float t, const vec3& v1) {
        return vec3{t * v1.e[0], t * v1.e[1], t * v1.e[2]};
    }

    vec3 operator/(vec3 v1, float t) {
        return vec3{v1.e[0] / t, v1.e[1] / t, v1.e[2] / t};
    }

    vec3 operator*(const vec3& v1, float t) {
        return vec3{t * v1.e[0], t * v1.e[1], t * v1.e[2]};
    }

    float dot(const vec3& v1, const vec3& v2) {
        return (v1.e[0] * v2.e[0]) + (v1.e[1] * v2.e[1]) + (v1.e[2] * v2.e[2]);
    }

    vec3 cross(const vec3& v1, const vec3& v2) {
        return vec3((v1.e[1] * v2.e[2] - v1.e[2]*v2.e[1]),
                   (-(v1.e[0] * v2.e[2] - v1.e[2]*v2.e[0])),
                   (v1.e[0] * v2.e[1] - v1.e[1]*v2.e[0]));
    }

    vec3 unit_vector(vec3 v) {
        return v / v.length();
    }
}