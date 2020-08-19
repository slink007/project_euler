/* Project Euler Program 4
 * A palindromic number reads the same both ways. The largest 
 * palindrome made from the product of two 2-digit numbers is 9009 
 * = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit 
 * numbers.
 *
 * Answer = 906609
*/


#include <string.h>
#include "numPalindrome/palindrome.h"


#define LOWER 100
#define UPPER 999


void printError(char* name);
void printHelp();
bool inputIsGood(int32_t, int32_t);


int main(int argc, char ** argv)
{
	uint32_t lower = LOWER;
	uint32_t upper = UPPER;
	uint32_t largest = 0;
	int32_t temp1;
	int32_t temp2;

	switch (argc)
	{
		case(3):  // user provided limits
			temp1 = atoi(argv[1]);
			temp2 = atoi(argv[2]);

			if (inputIsGood(temp1, temp2))
			{
				lower = (uint32_t)temp1;
				upper = (uint32_t)temp2;
			}
			else
				printError(argv[0]);
			break;
		case(2):
			if (strcmp("-h", argv[1]) == 0 ) // user requested help output
				printHelp();
			break;
		case(1):
		default:
			break;
	}

	// check all possible products within range
	for (uint32_t i = lower; i <= upper; i++)
	{
		for (uint32_t j = lower; j <= upper; j++)
		{
			uint32_t product = i * j;
			if ( (isPalindrome(product)) && (product > largest) )
				largest = product;
		}
	}

	printf("\nThe largest palindrome made by multiplying numbers between %u and %u (both inclusive) is %u\n\n",
			lower, upper, largest);

	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s \n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <lower> <upper>\n", name);
	fprintf (stderr,"<lower> and <upper> must be positive, whole numbers and <upper> must be\n"
			"larger than <lower>.\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
	printf("\nProject Euler Program 4\n\n"
		"A palindromic number reads the same both ways. The largest palindrome made from the product of two"
		"2-digit numbers is 9009 (made from 91 x 99).\n\nYou can run the program without arguments to solve"
		"this problem as stated.  You can optionally provide different lower and upper limits\n"
		"(both inclusive) to work out variations of this same problem.\n\n");

	exit (EXIT_SUCCESS);
}


bool inputIsGood(int32_t lower, int32_t upper)
{
	if (lower < 0 || upper < 0)
		return false;
	if (lower > upper)
		return false;
	return true;
}
