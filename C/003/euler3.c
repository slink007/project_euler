/* Project Euler Program 3
 * The prime factors of 13195 are 5, 7, 13 and 29.  What is the largest prime 
 * factor of the number 600851475143 ?
 *
 * Answer = 6857
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "primes/primes.h"

#define NUMBER 600851475143

void printError(char* name);
void printHelp();

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

	printf("\nThe largest prime factor of %zu is %zu\n\n", number, largestPrimeFactor(number));

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
	printf("\nProject Euler Program 3\n\n"
		"The prime factors of 13195 are 5, 7, 13 and 29.  What is the largest prime factor\n"
		"of the number 600851475143 ?\n\n"
		"You can run the program without arguments to solve this problem as stated.  You can optionally\n"
		"provide a different number to find the largest prime factor of.\n\n");

	exit (EXIT_SUCCESS);
}

