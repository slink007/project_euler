#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


// Returns True if 'n' is a prime number
bool isPrime(size_t n);


// Returns the nth prime number
size_t nthPrime(size_t n);


// Prime number generator.  On each call this function returns a new
// prime number (first 2, then 3, then 5, etc.).
size_t nextPrime(void);
