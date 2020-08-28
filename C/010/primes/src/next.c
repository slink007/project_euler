#include "primes/primes.h"


size_t nextPrime(void)
{
	static bool firstPrime = true;
	//static bool secondPrime = false;
	static bool firstTry = false;
	static bool secondTry = false;
	static size_t i = 1;
	size_t prime = 0, potentialPrime = 0;
	
	while (prime == 0)
	{
		if (firstTry)
		{
			potentialPrime = 6 * i - 1;
			if (isPrime(potentialPrime))
				prime = potentialPrime;
			
			firstTry = false;
			secondTry = true;
		}
		else if (secondTry)
		{
			potentialPrime = 6 * i + 1;
			if (isPrime(potentialPrime))
				prime = potentialPrime;
			
			firstTry = true;
			secondTry = false;
			i++;  // both formulas attempted so time to increment i
		}
		else if (firstPrime)  // first call to function, first prime = 2
		{
			prime = 2;
			firstPrime = false;  // don't call this block again
		}
		else  // second call to function, second prime is 3
		{
			prime = 3;
			firstTry = true;
		}
	}
	
	return prime;
}
