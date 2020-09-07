cmake_minimum_required(VERSION 3.0.0)
project(euler14 VERSION 1.0.0)

add_subdirectory(collatz)
add_executable(euler14
euler14.c)

set_property(TARGET euler14 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler14 PRIVATE collatz)
