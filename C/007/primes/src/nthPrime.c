#include "primes/primes.h"


size_t nthPrime(size_t n)
{
	size_t count = 0;
	size_t prime = 2;
	
	while (count < n)
	{
		prime = nextPrime();
		count++;
	}
	
	return prime;
}
