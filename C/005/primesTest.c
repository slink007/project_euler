#include <stdio.h>
#include <stdlib.h>

#include "primes/primes.h"


int main()
{
	printf("Expect: 1 2 3 5 7 11 13 17 19\n");
	for (uint32_t i = 0; i < 20; i++)
	{
		if (isPrime(i))
			printf("%u ", i);
	}
	printf("\n");

	// If includes are correct then this won't throw compile time error.
	Node* x = NULL;
	
	
	// Test prime factor
	for (uint32_t i = 1; i < 21; i++)
	{
		printf("The prime factors of %u are: ", i);
		primeFactor(i);
		printf("\n");
	}
	
	// Test leastCommonMultiple
	Node* primes = NULL;
	push(&primes, 2);
	push(&primes, 3);
	push(&primes, 5);
	push(&primes, 7);
	
	uint32_t lcm = leastCommonMultiple(&primes, 10);
	printf("\nThe LCM for numbers from 1 to 10 is %u\n\n", lcm);
	
	return EXIT_SUCCESS;
}
