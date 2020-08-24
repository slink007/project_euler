#include "primes/primes.h"


bool isPrime(size_t n)
{
	if (n == 0)
		return false;
		
	if (n == 1)
		return true;
	
	// Any prime factors will be sqrt(n) or lower so no need to
	// check anything higher than that. 
	for (size_t i = 2; (i*i) <= n; i++)
	{
		if ( (n % i) == 0 )
			return false;
	}
	return true;
}


size_t nthPrime(size_t n)
{
}
