/* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 * This is asking for the Least Common Multiple (LCM) of the listed numbers.  The process is:
 *     1. Find all prime numbers in that list and multiply them together.
 *     2. Break all the non-prime nummers down into prime products.  '9' becomes 3 * 3 or 3^2,
 *        '10' becomes 2 * 5, and so on.
 *     3. Determine how many times a prime number appears in the numbers from (2) and use that
 *        frequency to multiply the prime number by the product from (1).  For example, if
 *        the highest occurance of 2 was 3, achieved by 8 = 2 * 2 * 2, then we would multiply
 *        the product from (1) by 2 * 2 * 2.
 *
 * Answer = 232792560
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack/stack.h"
#include "primes/primes.h"

#define LOWER 1
#define UPPER 20

int main()
{
	uint32_t lower = LOWER;
	uint32_t upper = UPPER;
	Node* primes = NULL;
	Node* notPrimes = NULL;
	
	// break factors out into primes and non-primes
	for (uint32_t i = upper; i >= lower; i--)
	{
		if (isPrime(i))
			push(&primes, i);
		else
			push(&notPrimes, i);
	}
	
	// debug - validate that numbers are split out correctly
	uint32_t* n = NULL;
	printf("\nprimes contains: ");
	while (primes != NULL)
	{
		n = pop(&primes);
		printf("%u ", *n);
	}
	
	printf("\n\nnotPrimes contains: ");
	while (notPrimes != NULL)
	{
		n = pop(&notPrimes);
		printf("%u ", *n);
	}

	return(EXIT_SUCCESS);
}
