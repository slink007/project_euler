#include "primes/primes.h"


size_t largestPrimeFactor(size_t number)
{
	size_t n = 2;
	size_t factor = 1;

	while (n++ <= number)
	{
		while (number % n == 0) // n is a factor
		{
			number /= n;
			factor = n;
		}
	}
	return factor;
}
