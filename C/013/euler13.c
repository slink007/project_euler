/* Project Euler Program 13
* Work out the sum of one-hundred numbers which are 50-digits long.
*
* Return the 10 most significant digits. from the sum.  While not a 
* requirement for this problem these numbers are located in a separate 
* text file.
* 
* Answer = 5537376230
* 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringmath/add.h"


// Number of digits in numbers to be added
#define LENGTH 50

// If we had a single digit number the highest possible value is 9.
// If 50 of those are added together we get 450.  If we increase to
// a 2 digit number, 99, and add 50 of those together we get 4950.
// In all cases the sum is "n + 2" digits long.  Need another digit
// for '\0'.
#define SUMLENGTH (LENGTH + 2 + 1)

// number digits + '\0' + line feed due to getline()
#define LINELENGTH (LENGTH + 1 + 1)


void printError(char* name);
void printHelp();
void zeroes(char *c, unsigned int length);


int main(int argc, char ** argv)
{
	if (argc == 1)
		printError(argv[0]);
	else if (argc == 2)
	{
		if (strcmp("-h", argv[1]) == 0 )
			printHelp();
	}

	// Try to open file
	FILE *f = NULL;
	f = fopen(argv[1], "r");
	if (f)
	{
		char *line = malloc((LINELENGTH) * sizeof(char));
		if (line == NULL)
		{
			perror("Not enough memory to read from file\n");
			fclose(f);
			return EXIT_FAILURE;
        }


		char *sum = malloc((SUMLENGTH) * sizeof(char));
		if (sum == NULL)
		{
			perror("Not enough memory to create sum\n");
			fclose(f);
			free(line);
			return EXIT_FAILURE;
		}


		// Let's read from the file
		int characters = 0;  // How many characters did we read
		size_t size = 0;

		// Initialize sum to zero
		zeroes(sum, SUMLENGTH);

		int carry = 0;
		while (characters = getline(&line, &size, f) >= 0)
		{
			getSum(line, sum);
		}
		fclose(f);

		printf("\nThe sum is %s\n", sum);
		printf("The 10 most signifcant digits of the sum are %.10s\n\n", sum);

		free(line);
		free(sum);
		return EXIT_SUCCESS;
	}
	else
	{
		fprintf(stderr, "\nUnable to open file containing 50-digit numbers.\n\n");
		return (EXIT_FAILURE);
	}
}


void printError(char* name)
{
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <path to file> \n", name);
	fprintf (stderr,"The file is assumed to contain 50 numbers which are all"
        " 50 digits long\n");
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 13\n\n"
        "Add 50 numbers, each of which is 50 digits long, and return the 10"
        " most significant digits of their sum.\n\n");

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
