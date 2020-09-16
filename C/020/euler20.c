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


#define LEVEL 100


void printError(char* name);
void printHelp();


int main(int argc, char *argv[])
{
	
	unsigned int level = LEVEL;
	int temp;
	
	// process options from command line
	int option;
	while ( (option = getopt(argc, argv, "l:h")) != -1)
	{
		switch (option)
		{
			case 'l':  // choose different power to raise base to
				temp = atoi(optarg);
				if (temp < 0)
					printError(argv[0]);
				else
					level = (unsigned int)temp;
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
	for (unsigned int i = level; i > 0; i--)
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
		
	printf("\nThe sum of the digits in %u! is %llu.\n\n", level, sum);
	
	free(digits);
	return EXIT_SUCCESS;
}


void printError(char* name)
{
	fprintf (stderr,"\nUsage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s -b <base> -p <power>\n", name);
	fprintf (stderr,"<base> and <power> are both positive integers\n\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 16\n\n"
        "2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.\n"
        "What is the sum of the digits of 2^1000?\n\n"
        "You can solve this problem as-is or optionally enter a different base\n"
        "number and power to solve variations of this problem.\n"
        "Use -b <base> to change the base.\n"
        "Use -p <power> to change the power.\n\n");

    exit (EXIT_SUCCESS);
}

