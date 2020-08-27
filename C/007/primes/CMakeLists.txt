add_library(primes
src/primes.c
src/next.c
src/nthPrime.c)

target_include_directories(primes PUBLIC include)

