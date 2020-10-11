cmake_minimum_required(VERSION 3.0.0)
project(euler26 VERSION 1.0.0)

add_executable(euler26
euler26.c)

set_property(TARGET euler26 PROPERTY CXX_STANDARD 14)
#target_link_libraries(euler26 PRIVATE m)
