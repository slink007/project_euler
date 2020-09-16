cmake_minimum_required(VERSION 3.0.0)
project(euler20 VERSION 1.0.0)

#add_subdirectory(letterCount)
add_executable(euler20
euler20.c)

set_property(TARGET euler20 PROPERTY CXX_STANDARD 14)
#target_link_libraries(euler20 PRIVATE letterCount)
