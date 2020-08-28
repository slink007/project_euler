add_library(primes
src/primes.c
src/next.c
src/nthPrime.c)

target_include_directories(primes PUBLIC include)

# this should bring in libm which is needed for math.h
target_link_libraries(primes PRIVATE m)
