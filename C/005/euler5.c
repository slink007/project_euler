/* 2520 is the smallest number that can be divided by each of the 
 * numbers from 1 to 10 without any remainder.  What is the smallest 
 * positive number that is evenly divisible by all of the numbers from 
 * 1 to 20?
 *
 * Answer = 232792560
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack/stack.h"
#include "primes/primes.h"

#define UPPER 20

void printError(char* name);
void printHelp();


int main(int argc, char ** argv)
{
	uint32_t lower = 1;
	uint32_t upper = UPPER;
	uint32_t lcm;
	Node* primes = NULL;

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
				upper = (uint32_t)temp;
		}
	}
		
	// Build list of prime numbers less than or equal to the limit
	for (uint32_t i = upper; i > 0; i--)
	{
		if (isPrime(i))
			push(&primes, i);
	}
	
	lcm = leastCommonMultiple(&primes, upper);
	printf("\nThe smallest positive number that is evenly divisible by\n"
	"all of the numbers from %u to %u is %u.\n\n", lower, upper, lcm);
	
	return(EXIT_SUCCESS);
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
	printf("\nProject Euler Program 4\n\n"
		"2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without\n"
		"any remainder.  What is the smallest positive number that is evenly divisible by all of the\n"
		"numbers from 1 to 20?\n\n"
		"You can run the program without arguments to solve this problem as stated.  You can optionally\n"
		"provide a different number for the upper limit.\n\n");

	exit (EXIT_SUCCESS);
}

