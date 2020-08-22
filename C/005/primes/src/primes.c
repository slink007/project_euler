#include "primes/primes.h"


bool isPrime(uint32_t n)
{
	if (n == 0)
		return false;
		
	if (n == 1)
		return true;
	
	// Any prime factors will be sqrt(n) or lower so no need to
	// check anything higher than that. 
	for (uint32_t i = 2; (i*i) <= n; i++)
	{
		if ( (n % i) == 0 )
			return false;
	}
	return true;
}
