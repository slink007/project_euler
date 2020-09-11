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
#include "stringmath/multiply.h"


#define BASE 21
#define POWER 5


void printError(char* name);
void printHelp();
void zeroes(char *c, unsigned int length);
int numDigits(int n);


int main(int argc, char ** argv)
{
	// Create an initial product initialized to 1
	char *product = malloc(2 * sizeof(char));
	if (product == NULL)
	{
		perror("Unable to allocate memory for the answer\n");
		exit (EXIT_FAILURE);
	}
	strcpy(product, "1");
	
	// Convert the base number into a string
	unsigned int baseNum = BASE;
	char *base = malloc( (numDigits(baseNum) + 1) * sizeof(char) );
	if (base == NULL)
	{
		perror("Unable to allocate memory to hold the base number\n");
		exit (EXIT_FAILURE);
	}
	sprintf(base, "%d", baseNum);
	
	// Convert the power into a string
	unsigned int powerNum = POWER;
	char *power = malloc( (numDigits(powerNum) + 1) * sizeof(char) );
	if (base == NULL)
	{
		perror("Unable to allocate memory to hold the power number\n");
		exit (EXIT_FAILURE);
	}
	sprintf(power, "%d", powerNum);
	
	
	printf("Testing with %s raised to the power of %s\n", base, power);
	printf("Product initially contains %s\n", product);
	
	// Raise the base to the power
	getProduct(base, power, product);
	
	printf("Now product contains %s\n", product);
	
	free(product);
	free(base);
	free(power);
	return EXIT_SUCCESS;
}


int numDigits(int n)
{
	if (n == 0)
		return 0;
		
	return (1 + numDigits(n / 10));
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s\n", name);
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <base> <power>\n", name);
	fprintf (stderr,"<base> and <power> are both positive integers\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 16\n\n"
        "21^5 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.\n\n"
        "You can solve this problem as-is or optionally enter a different base\n"
        "number and power to solve variations of this problem.\n\n");

    exit (EXIT_SUCCESS);
}


void zeroes(char *c, unsigned int length)
{
		char len = (char)length - 1;
		char i = 0;
		while (i < len)
		{
			*(c + i) = '0';
			i++;
		}
		*(c + i) = '\0';
}
