/* Project Euler Program 14
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 *     13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) 
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), it 
 * is thought that all starting numbers finish at 1.
 * 
 * Which starting number, under one million, produces the longest chain?
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "collatz/collatz.h"

void printError(char* name);
void printHelp();


#define NUMBER 1000000


int main(int argc, char ** argv)
{
	size_t number = NUMBER;
	
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
				number = (size_t)temp;
		}
	}
	
	size_t termCount = 0, maxTermCount = 0;
	size_t numToGenerateMax = 0;
	
	for (size_t i = 1; i < number; i++)
	{
		termCount = collatz(i);
		
		if (termCount > maxTermCount)
		{
			maxTermCount = termCount;
			numToGenerateMax = i;
		}
	}
	
	printf("\nThe number below %zu which yields the most terms is %zu\n",
		number, numToGenerateMax);
	printf("It generated %zu terms\n\n", maxTermCount);
	
	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <number> \n", name);
	fprintf (stderr,"<number> is a positive integer greater than zero\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 14\n\n"
        "The following iterative sequence is defined for the set of positive integers:\n\n"
		"n → n/2 (n is even)/n"
		"n → 3n + 1 (n is odd)\n\n"
		"Using the rule above, and starting with 13, we generate 10 terms on the way to\n"
        "reach 1.  Which starting number, under one million, produces the longest chain?\n\n"
        "You can solve this problem as-is or optionally provide a different limit number for\n"
        "generating the most terms.\n\n");

    exit (EXIT_SUCCESS);
}
