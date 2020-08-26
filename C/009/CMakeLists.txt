cmake_minimum_required(VERSION 3.0.0)
project(euler9 VERSION 1.0.0)

add_subdirectory(pythagoras)
add_executable(euler9
euler9.c)

set_property(TARGET euler9 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler9 PRIVATE pythagoras)

