/* Project Euler Program 10
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
*/


#include <stdio.h>
#include <string.h>
#include "primes/primes.h"

#define LIMIT 2000000


void printError(char* name);
void printHelp();


int main(int argc, char ** argv)
{
	size_t limit = LIMIT;
	size_t sum = 0;
	size_t prime = 0;
	
	if (argc == 2)
	{
		if (strcmp("-h", argv[1]) == 0 )
			printHelp();
		else
		{
			int32_t temp = atoi(argv[1]);
			if (temp < 0)
				printError(argv[0]);
			else
				limit = (size_t)temp;
		}
	}
	
	while (prime < limit)
	{
		sum += prime;
		prime = nextPrime();
	}
	
	printf("\nThe sum of the primes below %zu is %zu.\n\n", limit, sum);
	
	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s \n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <number>\n", name);
	fprintf (stderr,"<number> must be a positive, whole number.\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
	printf("\nProject Euler Program 10\n\n"
		"The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.\n"
		"Find the sum of all the primes below two million.\n\n"
		"You can run the program without arguments to solve this problem as stated.  "
		"You can optionally provide a different prime number.\n\n");

	exit (EXIT_SUCCESS);
}
