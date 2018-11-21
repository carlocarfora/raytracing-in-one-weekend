#include <iostream>
#include "catch.hpp"
#include "vec3.hpp"

TEST_CASE("Test member methods", "[vec3]") {
    cc::vec3 v1{1.0,1.0,1.0};
    REQUIRE(v1.e[0] == 1);
    REQUIRE(v1.x() == 1.0);
    REQUIRE(v1.y() == 1.0);
    REQUIRE(v1.z() == 1.0);
    REQUIRE(v1.r() == 1.0);
    REQUIRE(v1.g() == 1.0);
    REQUIRE(v1.b() == 1.0);
}