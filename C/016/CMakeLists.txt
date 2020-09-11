cmake_minimum_required(VERSION 3.0.0)
project(euler16 VERSION 1.0.0)

add_subdirectory(stringmath)
# add_subdirectory(triangle)
add_executable(euler16
euler16.c)

set_property(TARGET euler16 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler16 PRIVATE stringmath)
# target_link_libraries(euler16 PRIVATE triangle)
