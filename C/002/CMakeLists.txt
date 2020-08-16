cmake_minimum_required(VERSION 3.0.0)
project(euler2 VERSION 1.0.0)

add_subdirectory(fibonacci)
add_executable(euler2
euler2.c)

set_property(TARGET euler2 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler2 PRIVATE fibonacci)

