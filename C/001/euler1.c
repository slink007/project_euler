/* Project Euler Program 1
 * If we list all the natural numbers below 10 that are multiples of 3
 * or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * Answer = 233168
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naturalSum/limitSum.h"

int main(int argc, char ** argv)
{
	unsigned int num1, num2, limit;

	if ( argc == 2 )
	{
		if (strcmp("-h", argv[1]) == 0)
		{
			printf("Help file triggered\n");
			return EXIT_SUCCESS;
		}
	}
	else if (argc == 4)
	{
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		limit = atoi(argv[3]);
	}
	else if (argc == 1)
	{
		num1 = 3;
		num2 = 5;
		limit = 1000;
	}
	else 
	{
		fprintf (stderr,"Usage: %s <int 1> <int 2> <limit>\n", argv[0]);
		return EXIT_FAILURE;
	}

	printf("The sum of all the multiples of %d and %d below %d is %d\n", \
		num1, num2, limit, limitSum(num1, num2, limit));

	return EXIT_SUCCESS;
}
