#include <iostream>
#include "vec3.hpp"
#include "catch.hpp"

TEST_CASE("Test member methods", "[vec3 methods]") {
    cc::vec3 v1{1.0,1.0,1.0};
    REQUIRE(v1.e[0] == 1);
    REQUIRE(v1.x() == 1.0);
    REQUIRE(v1.y() == 1.0);
    REQUIRE(v1.z() == 1.0);
    REQUIRE(v1.r() == 1.0);
    REQUIRE(v1.g() == 1.0);
    REQUIRE(v1.b() == 1.0);
}

TEST_CASE("Test operator overloads", "[vec3 overloads]") {
    cc::vec3 v1{1.0,1.0,1.0};
    cc::vec3 v2{1.0,1.0,1.0};
    cc::vec3 v3{2.0,2.0,2.0};
    cc::vec3 v4 = v1 + v2;
    REQUIRE(v3 == v4);
    cc::vec3 v5{1.0,1.0,1.0};
    cc::vec3 v6{1.0,1.0,1.0};
    cc::vec3 v7{0.0,0.0,0.0};
    cc::vec3 v8 = v5 - v6;
    REQUIRE(v8 == v7);
    cc::vec3 v9{2.0,2.0,2.0};
    cc::vec3 v10{2.0,2.0,2.0};
    cc::vec3 v11{4.0,4.0,4.0};
    cc::vec3 v12 = v9 * v10;
    REQUIRE(v12 == v11);
    cc::vec3 v13{2.0,2.0,2.0};
    cc::vec3 v14{2.0,2.0,2.0};
    cc::vec3 v15{1.0,1.0,1.0};
    cc::vec3 v16 = v13 / v14;
    REQUIRE(v15 == v16);
    cc::vec3 v17 = 2.0 * v15;
    REQUIRE(v17 == v14);
    cc::vec3 v18 = v11 / 2.0;
    REQUIRE(v18 == v10);
    cc::vec3 v19 = v15 * 2.0;
    REQUIRE(v19 == v14);
    float v20 = cc::dot(v9, v10);
    REQUIRE(v20 == 12);
    cc::vec3 v21 = cc::cross(v9, v10);
    REQUIRE(v21 == v7);
}