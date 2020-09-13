cmake_minimum_required(VERSION 3.0.0)
project(euler17 VERSION 1.0.0)

add_subdirectory(letterCount)
add_executable(euler17
euler17.c)

set_property(TARGET euler17 PROPERTY CXX_STANDARD 14)
target_link_libraries(euler17 PRIVATE letterCount)
