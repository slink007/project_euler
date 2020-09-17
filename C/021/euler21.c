/* Project Euler Program 21
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n 
 * which divide evenly into n).  If d(a) = b and d(b) = a, where a ≠ b, then a 
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 * Answer = 31626
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "amicable/amicable.h"

#define LIMIT 10000

void printError(char* name);
void printHelp();

int main(int argc, char *argv[])
{
	unsigned int sumOfAmicable = 0;
	unsigned int testLimit = LIMIT;
	
	// process options from command line
	int option;
	int temp;
	while ( (option = getopt(argc, argv, "l:h")) != -1)
	{
		switch (option)
		{
			case 'l':  // choose different limit on amicable numbers
				temp = atoi(optarg);
				if (temp < 0)
					printError(argv[0]);
				else
					testLimit = (unsigned int)temp;
				break;
			case 'h':  // prints help text
				printHelp();
				break;
			case '?':  // unrecognized options and missing parameters
				printError(argv[0]);
				break;
		}
	}
	
	for (unsigned int a = 2; a < testLimit; a++)
	{
		unsigned int b = sumOfDivisors(a);
		
		/* Per the directions for match b ≠ a.  Using b > a
		 * ensures that plus also prevents going back over numbers
		 * which were already tested.
		 */
		 if ( (b > a) && (sumOfDivisors(b) == a) )
			sumOfAmicable += a + b;
	}
	
	printf("\nThe sum of amicable numbers below %u is %u\n\n", 
		testLimit, sumOfAmicable);
	
	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"\nUsage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s -l <limit>\n", name);
	fprintf (stderr,"<limit> is a positive integer\n\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 21\n\n"
        "Let d(n) be defined as the sum of proper divisors of n (numbers less than n\n"
		"which divide evenly into n).  If d(a) = b and d(b) = a, where a ≠ b, then a \n"
		"and b are an amicable pair and each of a and b are called amicable numbers.\n\n"
        "You can solve this problem as-is or optionally enter a different limit (1 -> N)\n"
        "Use -l <limit> to change the limit.\n\n");

    exit (EXIT_SUCCESS);
}
