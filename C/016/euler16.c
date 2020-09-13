/* Project Euler Program 16
 * 21^5 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 * 
 * Answer = 1366
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>    // for log10()
#include <unistd.h>  // for handling options


#define BASE 2
#define POWER 1000


void printError(char* name);
void printHelp();


int main(int argc, char *argv[])
{
	
	unsigned int base = BASE;
	unsigned int power = POWER;
	int temp, temp2;
	
	// process options from command line
	int option;
	while ( (option = getopt(argc, argv, "b:p:h")) != -1)
	{
		switch (option)
		{
			case 'b':  // choose different base number
				temp = atoi(optarg);
				if (temp < 1)
					printError(argv[0]);
				else
					base = (unsigned int)temp;
				break;
			case 'p':  // choose different power to raise base to
				temp2 = atoi(optarg);
				if (temp2 < 0)
					printError(argv[0]);
				else
					power = (unsigned int)temp2;
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
	
	/* Determine how big the storage needs to be to hold the digits and
	 * set aside that storage.
	 * From an online source I found that 
	 * num. digits = 1 + log (base^power).
	 * Using some algebra I rearranged this to 
	 * num.digits = 1 + (power * log(base)).
	 */
	unsigned int numDigits = (unsigned int)( 1 + (power * log10( (double)base )) );
	char *digits = malloc(numDigits * sizeof(char));
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
	for (unsigned int i = 1; i <= power; i++)
	{
		unsigned int carry = 0;
		unsigned int product = 1;
		for (unsigned int j = 0;  j <= limit; j++)
		{
			product = (digits[j] * base) + carry;
			digits[j] = product % 10;
			carry = product / 10;
			
			if ( (j == limit) && (carry != 0) )
				limit++;
		}
	}
	
	unsigned long long sum = 0;
	for (unsigned int x = 0; x <= limit; x++)
		sum += digits[x];
		
	printf("\nThe sum of the digits %d raised to the power of %d is %llu\n\n",
		base, power, sum);
	
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

