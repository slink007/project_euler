cmake_minimum_required(VERSION 3.0.0)
project(euler22 VERSION 1.0.0)

add_subdirectory(names)
add_executable(euler22
euler22.c)

set_property(TARGET euler22 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler22 PRIVATE names)
