cmake_minimum_required(VERSION 3.0.0)
project(euler1 VERSION 1.1.0)

add_subdirectory(naturalSum)
add_subdirectory(testInput)
add_executable(euler1
euler1.c)

set_property(TARGET euler1 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler1 PRIVATE naturalSum testInput)

