/* The sum of the squares of the first ten natural numbers is,
 *
 *   1^2 + 2^2 + ... + 10^2 = 385
 *
 *
 * The square of the sum of the first ten natural numbers is,
 *
 *   (1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten 
 * natural numbers and the square of the sum is 3025 − 385 = 2640.  Find
 * the difference between the sum of the squares of the first one 
 * hundred natural numbers and the square of the sum.
 */


/* I found several sources online for calculating this sort of thing.
 * The best one, in my opinion, was 
 * 
 * https://byjus.com/maths/sum-of-squares/
 * 
 * From there we see that the sum of the squares of the first 'n'
 * natural numbers is  [n * (n+1) * (2n+1)]/6.
 * 
 * The sum of the squares of the even numbers in the range of 'n'
 * natural numbers is  [2n * (n+1) * (2n+1)]/3.
 * 
 * The sum of the squares of the odd numbers in the range of 'n'
 * natural numbers is  [n * (2n+1) * (2n-1)]/3.
 * 
 */
 
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 100

void printError(char* name);
void printHelp();

int main(int argc, char ** argv)
{
	size_t n = N;
	
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
				n = (size_t)temp;
		}
	}
	
	size_t sos = (n * (n + 1) * (2 * n + 1)) / 6;
	
	printf("\nThe sum of the squares of the first %zu natural numbers"
	" is %zu.\n\n", n, sos);
	
	size_t total = 0;
	for (size_t i = 1; i <= n; i++)
	{
		total += i;
	}
	printf("The square of the sum of the first %zu natural numbers"
	" is %zu.\n\n", n, total * total);
	
	printf("The difference between the square of the sum and the sum of"
	" the squares is %zu.\n\n", (total * total) - sos);
	
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
	printf("\nProject Euler Program 6\n\n"
		"The sum of the squares of the first ten natural numbers is:\n"
		"     1^2 + 2^2 + ... + 10^2 = 385\n"
		"The square of the sum of the first ten natural numbers is:\n"
		"     (1 + 2 + ... + 10)^2 = 55^2 = 3025\n\n"
		"The difference between the sum of the squares of the first ten \n"
		"natural numbers and the square of the sum is 3025 − 385 = 2640.\n"
		"Find the difference between the sum of the squares of the first\n"
		"one  hundred natural numbers and the square of the sum.\n\n"
		"You can run the program without arguments to solve this problem\n"
		"as stated.  You can optionally provide a different number as \n"
		"limit for the range of natural numbers.\n\n");

	exit (EXIT_SUCCESS);
}
