/* Project Euler Program 25
 * The Fibonacci sequence is defined by the recurrence relation:
 * 
 * Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
 * 
 * Hence the first 12 terms will be:
 * 
 *  F1 = 1
 *  F2 = 1
 *  F3 = 2
 *  F4 = 3
 *  F5 = 5
 *  F6 = 8
 *  F7 = 13
 *  F8 = 21
 *  F9 = 34
 *  F10 = 55
 *  F11 = 89
 *  F12 = 144
 * 
 * The 12th term, F12, is the first term to contain three digits.
 * 
 * What is the index of the first term in the Fibonacci sequence to 
 * contain 1000 digits?
 * 
 * Answer = 4782
 */


/* Since the number of digits in the Fibonacci number is so high we will
 * use Binet's formula to find the nth Fibonacci term.  First we solve
 * ( (log 5)/2 + d - 1 ) / (log φ ).  Here 'd' is the number of digits
 * we want the Fibonacci number to have.   φ is (1 + sqrt(5)) / 2.
 * The answer to that function is then rounded up to the next nearest
 * integer.  This will be the answer to the problem.
 */


#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void printHelp();

int main(int argc, char *argv[])
{
	int digits = 1000;  // How many digits in the Fibonacci number
	
	// handle command line options
	int option;
	while ( (option = getopt(argc, argv, "hn:")) != -1)
	{
		switch(option)
		{
			case 'n':  // user enters a different number of permutations
				digits = atoi(optarg);
				if (digits < 1)
				{
					fprintf(stderr, "Number of digits must be a "
					"positive integer\n");
					return EXIT_FAILURE;
				}
				break;
			case 'h':  // User wants to print help message
				printHelp();
				exit (EXIT_SUCCESS);
				break;
			case '?':  // unrecognized options and missing parameters
				fprintf(stderr, "That shouldn't happen\n");
				exit (EXIT_FAILURE);
				break;
		}
	}
	
	float phi = (1 + sqrt(5)) / 2;
	float n = ( (log10(5) / 2) + digits - 1 ) / (log10(phi));
	int index = (int)n;
		
	// Algorithm breaks down for 1 digit numbers.  The first such number
	// is at index 1 so we don't increment in that case.
	if (index > 1)
		index++;
	
	printf("\nThe first Fibonacci number that is %d digits long is at index %d.\n\n",
		digits, index);
	
	return EXIT_SUCCESS;
}


void printHelp()
{
	printf("\nProject Euler Program 25\n"
	"The Fibonacci sequence is defined by the recurrence relation:\n"
	"Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.  The first few terms are:\n"
	"\tF1 = 1\n"
	"\tF2 = 1\n"
	"\tF3 = 2\n"
	"\tF4 = 3\n"
	"\tF5 = 5\n"
	"\tF6 = 8\n"
	"\tF7 = 13\n"
	"What is the index of the first term in the Fibonacci sequence to \n"
	"contain 1000 digits?\n\n"
	"You can optionally pass the -n option to change how many digits the\n"
	"Fibonacci number will have.\n\n");
}
