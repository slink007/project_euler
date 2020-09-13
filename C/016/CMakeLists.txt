cmake_minimum_required(VERSION 3.0.0)
project(euler16 VERSION 1.0.0)

add_executable(euler16
euler16.c)

set_property(TARGET euler16 PROPERTY CXX_STANDARD 14)

# libm for math.h
target_link_libraries(euler16 PRIVATE m)
