/* Project Euler Program 23
 * A perfect number is a number for which the sum of its proper divisors
 * is exactly equal to the number. For example, the sum of the proper 
 * divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 
 * is a perfect number.
 * 
 * A number n is called deficient if the sum of its proper divisors is 
 * less than n and it is called abundant if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the 
 * smallest number that can be written as the sum of two abundant 
 * numbers is 24. 
 * 
 * By mathematical analysis, it can be shown that all integers greater 
 * than 28123 can be written as the sum of two abundant numbers. 
 * However, this upper limit cannot be reduced any further by 
 * analysis even though it is known that the greatest number that cannot
 * be expressed as the sum of two abundant numbers is less than this 
 * limit.
 * 
 * Find the sum of all the positive integers which cannot be written as 
 * the sum of two abundant numbers.
 *
 * Answer = 4179871
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "abund/abundant.h"

void printHelp();

int main(int argc, char *argv[])
{
	// handle command line options
	int option;
	while ( (option = getopt(argc, argv, "h")) != -1)
	{
		switch (option)
		{
			case 'h':  // prints help text
				printHelp();
				exit (EXIT_SUCCESS);
				break;
			case '?':  // unrecognized options and missing parameters
				perror("That shouldn't happen\n");
				exit (EXIT_FAILURE);
				break;
		}
	}
	
	
	size_t sum = 0;
	
	/* Research into abundant numbers shows that integers above 20161
	 * can be expressed as the sum of 2 abundant numbers.  This is
	 * lower than the limit from the problem statement. */
	size_t limit = 20162;
	
	testNumbersForAbundance();
	
	for (size_t i = 1; i < limit; i++)
	{
		if ( notAbundantSum(i) )
			sum += i;
	}
	
	printf("\nThe sum of all the positive integers which cannot be"
	       " written as the sum of two abundant numbers is %zu.\n\n", sum);
	
	return EXIT_SUCCESS;
}


void printHelp()
{
	printf("\nProject Euler Program 23\n"
           "A perfect number is a number for which the sum of its proper\n"
           "divisors is exactly equal to the number. For example, the sum\n"
           "of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,\n"
           "which means that 28 is a perfect number.\n\n"
           "A number n is abundant if this sum of divisors exceeds n.\n"
           "As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,\n"
           "the smallest number that can be written as the sum of two abundant\n"
           "numbers is 24. \n\n"
           "Find the sum of all the positive integers which cannot be written\n"
           "as the sum of two abundant numbers.\n");
}
