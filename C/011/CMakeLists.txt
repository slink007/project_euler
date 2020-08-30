cmake_minimum_required(VERSION 3.0.0)
project(euler11 VERSION 1.0.0)

add_subdirectory(arrays)
add_executable(euler11
euler11.c)

set_property(TARGET euler11 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler11 PRIVATE arrays)

