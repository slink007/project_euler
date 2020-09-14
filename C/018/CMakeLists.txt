cmake_minimum_required(VERSION 3.0.0)
project(euler18 VERSION 1.0.0)

#add_subdirectory(letterCount)
add_executable(euler18
euler18.c)

set_property(TARGET euler18 PROPERTY CXX_STANDARD 14)
#target_link_libraries(euler18 PRIVATE letterCount)
