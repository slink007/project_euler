#include "primes/primes.h"


bool isPrime(size_t n)
{
	if (n < 2)
		return false;
	
	if (n == 2)
		return true;
		
	// Any prime factors will be sqrt(n) or lower so no need to
	// check anything higher than that. 
	for (size_t i = 3; (i*i) <= n; i += 2)
	{
		if ( (n % i) == 0 )
			return false;
	}
	return true;
}


