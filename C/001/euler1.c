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
#include "testInput/testInput.h"


void printError(char* name);
void printHelp();

int main(int argc, char ** argv)
{
	unsigned int num1 = 3, num2 = 5, limit = 1000;

	if ( (argc == 2) )
	{
		if (strcmp("-h", argv[1]) == 0 ) 
			printHelp();
		else
			printError(argv[0]);
	}	
	else if (argc == 4)
	{
		int temp1 = atoi(argv[1]);
		int temp2 = atoi(argv[2]);
		int temp3 = atoi(argv[3]);
		if (isValid(temp1, temp2, temp3))
		{
			num1 = (unsigned)temp1;
			num2 = (unsigned)temp2;
			limit = (unsigned)temp3;
		}
		else
			printError(argv[0]);
	}
	else if (argc > 1) 
	{
		printError(argv[0]);
	}

	printf("The sum of all the multiples of %u and %u below %u is %u\n", \
		num1, num2, limit, limitSum(num1, num2, limit));

	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s <int 1> <int 2> <limit>\n", name);
	fprintf (stderr,"All values must be positive, whole numbers.\n");
	fprintf (stderr,"<int 1> and <int 2> must be less than <limit>\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
	printf("Project Euler Program 1\n");
	printf("If we list all the natural numbers below 10 that are"
	" multiples of 3 or 5 we get 3, 5, 6 and 9. The sum of these "
	"multiples is 23.\n\n");
	printf("Calling this program with no arguments solves this problem"
	" as stated.\n");
	printf("You can optionally provide two numbers, and a limit, to"
	" solve variations of this problem.\n");
	
	exit (EXIT_SUCCESS);
}
