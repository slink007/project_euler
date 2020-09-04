cmake_minimum_required(VERSION 3.0.0)
project(euler12 VERSION 1.0.0)

add_subdirectory(primes)
add_executable(euler12
euler12.c)

set_property(TARGET euler12 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler12 PRIVATE primes)

