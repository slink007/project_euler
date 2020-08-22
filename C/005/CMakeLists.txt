cmake_minimum_required(VERSION 3.0.0)
project(euler5 VERSION 1.0.0)

add_subdirectory(list)
add_subdirectory(primes)
add_executable(euler5
euler5.c)

set_property(TARGET euler5 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler5 PRIVATE list primes)

