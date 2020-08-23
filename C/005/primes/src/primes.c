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


// 'primes' is a stack which contains all prime numbers below the 
// 'upper'limit.  To find the Least Common Multiple we multiply all 
// those prime numbers together.  The exception is that if an exponent
// of the prime exists below the limit then we use that exponent instead
// of the prime.
uint32_t leastCommonMultiple(Node** primes, uint32_t upper)
{
	uint32_t product = 1;
	
	// process all prime numbers
	while (isNotEmpty(primes))
	{
		uint32_t primeNumber = pop(primes);
		uint32_t temp = primeNumber;
		
		// If 'n' were a prime number but n * n, or n * n * n, were 
		// belowe the limit then use those exponents instead.
		while ( (primeNumber > 1) && (temp * primeNumber) < upper)
			temp *= primeNumber;
		
		product *= temp;
	}
	
	return product;
}

// I wound up not needing this but left it here in case it might be
// useful for some other Euler problem.
void primeFactor(uint32_t n)
{
	if (n == 1)
	{
		printf("1");
		return;
	}
	if (n == 2)
	{
		printf("2");
		return;
	}
	
	uint32_t i = 2;
	
	while ( (i*i) <= n )
	{
		while (n % i == 0)
		{
			n /= i;
			printf("%u ", i);
		}
		i++;
	}
	
	// Handle prime numbers
	if (n > 2)
		printf("%u", n);
}
