cmake_minimum_required(VERSION 3.0.0)
project(euler23 VERSION 1.0.0)

add_subdirectory(abund)
add_executable(euler23
euler23.c)

set_property(TARGET euler23 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler23 PRIVATE abund)
