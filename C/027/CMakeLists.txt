cmake_minimum_required(VERSION 3.0.0)
project(euler27 VERSION 1.0.0)

add_executable(euler27
euler27.c)

set_property(TARGET euler27 PROPERTY CXX_STANDARD 14)
#target_link_libraries(euler27 PRIVATE m)
