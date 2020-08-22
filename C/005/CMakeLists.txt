cmake_minimum_required(VERSION 3.0.0)
project(euler5 VERSION 1.0.0)

add_subdirectory(stack)
add_subdirectory(primes)

# main executable
add_executable(euler5
euler5.c)
set_property(TARGET euler5 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler5 PRIVATE stack primes)

# test for stack library
add_executable(stackTest
stackTest.c)
set_property(TARGET stackTest PROPERTY CXX_STANDARD 14)
target_link_libraries(stackTest PRIVATE stack)

# test for primes library
add_executable(primesTest
primesTest.c)
set_property(TARGET stackTest PROPERTY CXX_STANDARD 14)
target_link_libraries(primesTest PRIVATE primes)
