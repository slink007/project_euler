cmake_minimum_required(VERSION 3.0.0)
project(euler21 VERSION 1.0.0)

#add_subdirectory(letterCount)
add_executable(euler21
euler21.c)

set_property(TARGET euler21 PROPERTY CXX_STANDARD 14)
#target_link_libraries(euler21 PRIVATE letterCount)
