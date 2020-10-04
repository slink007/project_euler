cmake_minimum_required(VERSION 3.0.0)
project(euler25 VERSION 1.0.0)

add_executable(euler25
euler25.c)

set_property(TARGET euler25 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler25 PRIVATE m)
