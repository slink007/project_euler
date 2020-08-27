/* Project Euler Program 7
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see 
 * that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 * 
 * Answer = 104743
*/

#include <stdio.h>
#include <string.h>
#include "primes/primes.h"

#define LIMIT 10001

void printError(char* name);
void printHelp();

int main(int argc, char ** argv)
{
	size_t limit = LIMIT;
	
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
	
	printf("\nPrime #%zu is %zu\n\n", limit, nthPrime(limit));
	
	
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
	printf("\nProject Euler Program 7\n\n"
		"By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see\n"
		"that the 6th prime is 13.\n\n"
		"What is the 10 001st prime number?\n\n"
		"You can run the program without arguments to solve this problem as stated.  "
		"You can optionally provide a different prime number to look for.\n\n");

	exit (EXIT_SUCCESS);
}

