#include "primes/primes.h"

size_t largestPrimeFactor(size_t number)
{
	size_t n = 2;
	size_t factor = 1;

	while (n <= number)
	{
		while (number % n == 0) // n is a factor
		{
			number /= n;
			factor = n;
		}
		n++;
	}
	return factor;
}


size_t divisorCount(size_t number)
{
	size_t divisors = 1;  // there is always at least one divisor
	
	while (numbers > 1)
	{
		size_t p = nextPrime();
		size_t count = 0;
		
		while (number % p == 0)
		{
			number /= p;
			count++;
		}
		
		if (count != 0)  // at least one prime factor discovered
			divisors*= (count + 1);
	}
	
	return divisors;
}
