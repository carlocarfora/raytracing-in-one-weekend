//
// Created by carlo on 11/11/18.
//

#include "../include/vec3.hpp"
#include <iostream>

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

//    vec3 &vec3::operator+=(const vec3 &v2) {
//        return <#initializer#>;
//    }
//
//    vec3 &vec3::operator-=(const vec3 &v2) {
//        return <#initializer#>;
//    }
//
//    vec3 &vec3::operator*=(const vec3 &v2) {
//        return <#initializer#>;
//    }
//
//    vec3 &vec3::operator/=(const vec3 &v2) {
//        return <#initializer#>;
//    }
//
//    vec3 &vec3::operator*=(const float t) {
//        return <#initializer#>;
//    }
//
//    vec3 &vec3::operator/=(const float t) {
//        return <#initializer#>;
//    }

    std::istream& operator>>(std::istream& is, vec3& t) {
        is >> t.e[0] >> t.e[1] >> t.e[2];
        return is;
    }

    std::ostream& operator<<(std::ostream &os, vec3 &t) {
        os << t.e[0] << " " << t.e[1] << " " << t.e[2];
        return os;
    }
}