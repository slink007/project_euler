/* Project Euler Program 26
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 *
 * 1/2	= 	0.5
 * 1/3  =   0.(3)
 * 1/4  =   0.25
 * 1/5  =   0.2
 * 1/6  =   0.1(6)
 * 1/7  =   0.(142857)
 * 1/8  =   0.125
 * 1/9  =   0.(1)
 * 1/10 =   0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can
 * be seen that 1/7 has a 6-digit recurring cycle.  Find the value of
 * d < 1000 for which 1/d contains the longest recurring cycle in its decimal
 * fraction part.
 *
 * Answer = 983
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#define LIMIT 1000  // The upper limit from the problem statement


/* Returns a count of the recurring digits in the quotient of 1 
 * divided by 'n'.  It is assumed that 'n' is a positive integer.
 */
int recursiveDigits(unsigned int n);
void printHelp();


int main(int argc, char *argv[])
{
	int count = 0;
	int maxCount = 0;
	int maxIndex = 0;
	int limit = LIMIT;
	
	// handle command line options
	int option;
	while ( (option = getopt(argc, argv, "hn:")) != -1)
	{
		switch (option)
		{
			case 'h':  // prints help text
				printHelp();
				exit (EXIT_SUCCESS);
				break;
			case 'n':  // user enters a different limit number
				limit = atoi(optarg);
				if (limit < 2)
				{
					fprintf(stderr, "Upper limit must be a positive"
					" integer which is 2 or greater.\n");
					return EXIT_FAILURE;
				}
				break;
			case '?':  // unrecognized options and missing parameters
				fprintf(stderr, "That shouldn't happen\n");
				exit (EXIT_FAILURE);
				break;
		}
	}
	
	for (int i = 1; i < limit; i++)
	{
		count = recursiveDigits(i);
		if (count > maxCount)
		{
			maxCount = count;
			maxIndex = i;
		}
	}
	
	printf("\n%d has %d recurring digits which is more than any other "
		"number greater than 1 and less than %d.\n\n", 
		maxIndex, maxCount, limit);
	
	return EXIT_SUCCESS;
}


int recursiveDigits(unsigned int n)
{
	/* Any number 'n' will have, at most, n-1 recurring digits when
	 * we divide it into 1.
	 */
	int previousRemainders[n];
	
	/* Make sure that everything in the list starts off with a number
	 * which won't result from doing the division.
	 */
	for (int i = 0; i < n; i++)
		previousRemainders[i] = -1;
	
	int remainder = 1 % n;
	int i = 0;
	previousRemainders[i] = remainder;
	
	while (i++ < n)
	{
		remainder = (10 * remainder) % n;

		// If number divides evenly we have no repeating digits.
		if (remainder == 0)
			return 0;
		
		/* Check to see if the current remainder has been seen before.
		 * If so the count of repeating digits is the current value of i
		 * minus the index where the original value is stored.
		 */
		for (int j = 0; j  <= i; j++)
		{
			if (remainder == previousRemainders[j])
				return i - j;
		}
		
		// New remainder so add it to the list.
		previousRemainders[i] = remainder;
	}
	
	// No repeating digits could be found.
	return 0;
}


void printHelp()
{
	printf("\nProject Euler Program 26\n"
		"A unit fraction contains 1 in the numerator. The decimal \n"
		"representation of the unit fractions with denominators 2 to \n"
		"10 are given:\n\n"
		"1/2  =   0.5\n1/3  =   0.(3)\n1/4  =   0.25\n"
		"1/5  =   0.2\n1/6  =   0.1(6)\n1/7  =   0.(142857)\n"
		"1/8  =   0.125\n1/9  =   0.(1)\n1/10 =   0.1\n\n"
		"Where 0.1(6) means 0.166666..., and has a 1-digit recurring \n"
		"cycle. It can be seen that 1/7 has a 6-digit recurring cycle.\n"
		"Find the value of d < 1000 for which 1/d contains the longest \n"
		"recurring cycle in its decimal.\n"
		"You can optionally pass the -n option to change the upper \n"
		"limit.\n\n");
}
