cmake_minimum_required(VERSION 3.0.0)
project(euler8 VERSION 1.0.0)

add_subdirectory(primes)
add_executable(euler8
euler8.c)

set_property(TARGET euler8 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler8 PRIVATE primes)

