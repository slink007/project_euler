/* Project Euler Program 2
 * Each new term in the Fibonacci sequence is generated by adding the 
 * previous two terms. By starting with 1 and 2, the first 10 terms 
 * will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do 
 * not exceed four million, find the sum of the even-valued terms.
 *
 * Answer = 4613732
*/


#include <stdio.h>
#include <stdlib.h>
#include "fibonacci/fibonacci.h"

#define LIMIT 4000000

void printError(char* name);
void printHelp();


int main(int argc, char ** argv)
{
	fibNum f = firstFibonacci();
	uint32_t total = 0;

	while (f.num <= LIMIT)
	{
		if (f.num % 2 == 0)
			total += f.num;
		nextFib(&f);
	}

	printf("Sum of even Fibonacci numbers below %u is %u\n", LIMIT, total);

	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s \n", name);
	fprintf (stderr,"Usage: %s <limit>\n", name);
	fprintf (stderr,"<limit> must be a positive, whole number.\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
	printf("\nProject Euler Program 2\n\n"
           "Each new term in the Fibonacci sequence is generated by adding the previous two terms.\n"
           "By starting with 1 and 2, the first 10 terms will be:\n\n"
           "1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...\n\n"
           "By considering the terms in the Fibonacci sequence whose values do not exceed four\n"
           "million, find the sum of the even-valued terms.\n"
           "You can run the program without arguments to solve this problem as stated.  You can optionally\n"
           "provide a different limit to work out variations of this same problem.\n\n");

	exit (EXIT_SUCCESS);
}
