cmake_minimum_required(VERSION 3.0.0)
project(euler15 VERSION 1.0.0)

add_subdirectory(paths)
add_executable(euler15
euler15.c)

set_property(TARGET euler15 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler15 PRIVATE paths)
