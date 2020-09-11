cmake_minimum_required(VERSION 3.0.0)
project(euler13 VERSION 1.0.0)

add_subdirectory(stringmath)
# add_subdirectory(triangle)
add_executable(euler13
euler13.c)

set_property(TARGET euler13 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler13 PRIVATE stringmath)
# target_link_libraries(euler13 PRIVATE triangle)
