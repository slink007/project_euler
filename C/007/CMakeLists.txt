cmake_minimum_required(VERSION 3.0.0)
project(euler7 VERSION 1.0.0)

add_subdirectory(primes)
add_executable(euler7
euler7.c)

set_property(TARGET euler3 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler3 PRIVATE primes)

