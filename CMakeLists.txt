cmake_minimum_required(VERSION 3.12)
project(raytracing_in_one_weekend)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracing_in_one_weekend src/main.cpp src/vec3.cpp include/vec3.hpp)
add_executable(raytracing_in_one_weekend_tests test/test-main.cpp include/vec3.hpp src/vec3.cpp test/test-vec3.cpp)

target_include_directories(raytracing_in_one_weekend_tests PRIVATE include/)