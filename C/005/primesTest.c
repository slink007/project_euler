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
	
	return EXIT_SUCCESS;
}
