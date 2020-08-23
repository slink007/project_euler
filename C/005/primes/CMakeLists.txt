add_library(primes
src/primes.c)

target_include_directories(primes PUBLIC  ../stack)
target_include_directories(primes PUBLIC include)
target_link_libraries(primes PUBLIC stack)


