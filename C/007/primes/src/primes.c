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


size_t nthPrime(size_t n)
{
	// Once you get beyond 2 & 3 all prime numbers meet the criteria
	// of 6x + 1 or 6x - 1.  Example: if we let x = 1 that will 
	// generate 6(1) + 1 = 7 and 6(1) - 1 = 5.  Both 7 & 5 are prime.
	// We don't always get primes on both variants but we will always
	// get at least one prime.
	
	size_t count = 2;
	size_t i = 1;
	size_t prime = 3;
	size_t possiblePrime;
	
	// 1st prime is 2
	if (n == 1)
		return 2;
	
	while (count < n)
	{
		possiblePrime = 6 * i - 1;
		if (isPrime(possiblePrime))
		{
			prime = possiblePrime;
			count++;
		}
		
		if (count >= n)
			break;
		
		possiblePrime = 6 * i + 1;
		if (isPrime(possiblePrime))
		{
			prime = possiblePrime;
			count++;
		}
		
		i++;
	}
	
	return prime;
}
