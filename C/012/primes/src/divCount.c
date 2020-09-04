#include "primes/primes.h"

#define LIMIT 60
size_t primesList[LIMIT] = {  2,   3,   5,   7,  11,  13,  17,  19,  23,
	                         29,  31,  37,  41,  43,  47,  53,  59,  61,
	                         67,  71,  73,  79,  83,  89,  97, 101, 103,
	                        107, 109, 113, 127, 131, 137, 139, 149, 151,
	                        157, 163, 167, 173, 179, 181, 191, 193, 197, 
	                        199, 211, 223, 227, 229, 233, 239, 241, 251, 
	                        257, 263, 269, 271, 277, 281};

/* This leverages two mathematical principles.
 * 1) Any whole number N can be expressed as the product of prime factors
 *    and each of these factors will be raised to some power.
 *    N = p^A * p^B * ... * pN
 *    Ex: 28 = (2^2) * (7^1) = 4 * 7
 * 
 * 2) If we take each of those products, and add 1 to them, and then 
 *    multiply the results together, we get the number of factors for
 *    the base number.
 *    Example:  28 has factors 1, 2, 4, 7, 14, and 28 (6 total).
 *    From #1 above we have exponents of 2 and 1.
 *    D(N) = (2 + 1) * (1 + 1) = 3 * 2 = 6
 */
size_t divisorCount(size_t number)
{
	if (number == 0)
	{
		perror("Divide by zero in divisorCount()\n");
		exit (EXIT_FAILURE);
	}
	
	size_t divisors = 1;  // there is always at least one divisor
	size_t index = 0;
	size_t p;
	
	while (number > 1 && index < LIMIT)
	{
		size_t count = 0;  // exponent of prime factor
		p = primesList[index++];
		
		while (number % p == 0)
		{			
			number /= p;
			count++;
		}
		
		if (count != 0)  // at least one prime factor discovered
			divisors *= (count + 1);  // update per #2 in description
	}
	
	return divisors;
}
