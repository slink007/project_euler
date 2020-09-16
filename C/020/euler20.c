/* Project Euler Program 20
 * 
 * n! means n × (n − 1) × ... × 3 × 2 × 1
 * 
 * For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of
 * the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 * Find the sum of the digits in the number 100!
 * 
 * Answer = 648
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // for handling options


#define NUMBER 100


void printError(char* name);
void printHelp();


int main(int argc, char *argv[])
{
	
	unsigned int number = NUMBER; // the number to take the factorial of
	
	// process options from command line
	int temp;
	int option;
	while ( (option = getopt(argc, argv, "n:h")) != -1)
	{
		switch (option)
		{
			case 'n':  // choose different power to raise base to
				temp = atoi(optarg);
				if ( (temp < 0) || (temp > 100) )
					printError(argv[0]);
				else
					number = (unsigned int)temp;
				break;
			case 'h':  // prints help text
				printHelp();
				break;
			case '?':  // unrecognized options and missing parameters
				printError(argv[0]);
				break;
		}
	}
	
	unsigned int limit = 0;  // controls how far to work into digits
	
	/* 200 is semi-arbitrary.  It's enough digits to hold the answer
	 * and a little more.
	 */
	char *digits = malloc(200 * sizeof(char));
	
	
	if (digits == NULL)
	{
		perror("Not enough memory available\n");
		return EXIT_FAILURE;
	}
	digits[0] = 1;  // 1 because 1 * anything = that thing
	
	
	/* The 'digits' array is like a scratchpad which will hold the
	 * product of multiplying by 'base'.  It's reverse order vs. normal
	 * so MSD -> LSD.  This doesn't matter for this problem as all we
	 * want is the sum of the digits.
	 * 
	 * This works just like old school pencil & paper multiplication.
	 * Multiply two numbers, if product is more than ten we keep the
	 * "one's" part of the number and assign the rest to the "carry".
	 * For the next digit we repeat and add on the "carry" (if any).
	 */
	for (unsigned int i = number; i > 0; i--)
	{
		unsigned int carry = 0;
		unsigned int product = 1;
		for (unsigned int j = 0;  j <= limit; j++)
		{
			product = (digits[j] * i) + carry;
			digits[j] = product % 10;
			carry = product / 10;
			
			if ( (j == limit) && (carry != 0) )
				limit++;
		}
	}
	
	unsigned long long sum = 0;
	for (unsigned int x = 0; x <= limit; x++)
		sum += digits[x];
		
	printf("\nThe sum of the digits in %u! is %llu.\n\n", number, sum);
	
	free(digits);
	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"\nUsage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s -n <number>\n", name);
	fprintf (stderr,"<number> is a positive integer which is 100 or lower.\n\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 20\n\n"
		"n! means n × (n − 1) × ... × 3 × 2 × 1\n\n"
		"For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of\n"
		"the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.\n\n"
		"Find the sum of the digits in the number 100!\n"
        "You can solve this problem as-is or optionally enter a different number\n"
        "to solve variations of this problem.\n"
        "Use -n <number> to change the number to take the factorial of.  <number>\n"
		"must be 100 or lower.\n\n");

    exit (EXIT_SUCCESS);
}

