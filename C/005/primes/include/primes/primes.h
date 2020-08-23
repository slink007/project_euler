#ifndef __PRIMES_H_
#define __PRIMES_H_


#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "stack/stack.h"


// Return true if 'n' is a prime number
bool isPrime(uint32_t n);


void primeFactor(uint32_t n);

// Pass in a list of prime numbers which are below or equal to the 
// upper limit, along with that limit, and this will return the smallest
// number which can be evenly divided by all whole numbers from 1 to 
// the upper limit.
uint32_t leastCommonMultiple(Node** primes, uint32_t upper);

#endif
