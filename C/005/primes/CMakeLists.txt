add_library(primes
src/primes.c)

# original command
# target_include_directories(primes PUBLIC include)

# new command to try and include the stack library
target_include_directories(primes PUBLIC include ../stack/include/stack)

