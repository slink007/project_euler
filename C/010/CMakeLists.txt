cmake_minimum_required(VERSION 3.0.0)
project(euler10 VERSION 1.0.0)

add_subdirectory(primes)
add_executable(euler10
euler10.c)

set_property(TARGET euler10 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler10 PRIVATE primes)

