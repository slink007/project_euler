cmake_minimum_required(VERSION 3.0.0)
project(euler4 VERSION 1.0.0)

add_subdirectory(numPalindrome)
add_executable(euler4
euler4.c)

set_property(TARGET euler4 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler4 PRIVATE numPalindrome)

