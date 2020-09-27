add_library(abund
src/abundant.c)

target_include_directories(abund PUBLIC include)
# this should bring in libm which is needed for math.h
target_link_libraries(abund PRIVATE m)
