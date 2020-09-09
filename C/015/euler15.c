/* Project Euler Program 15
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20×20 grid?
 *
 * Answer = 137846528820
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>  // only needed for thousands separator in output
#include "paths/paths.h"

#define ROWS 20
#define COLS 20

void printError(char* name);
void printHelp();

int main(int argc, char ** argv)
{
	unsigned long rows = ROWS;
	unsigned long cols = COLS;

	if (argc == 2)
	{
		if (strcmp("-h", argv[1]) == 0 )
			printHelp();
	}
	else if (argc == 3)
	{
		int tempRow = atoi(argv[1]);
		int tempCol = atoi(argv[2]);
		if ( (tempRow < 0) || (tempCol < 0) )
			printError(argv[0]);
		else
		{
			rows = (unsigned long)tempRow;
			cols = (unsigned long)tempCol;
		}
	}

	// The following 4 lines are just to get a thousands separator for the output.
	// They are not expected to work on non-POSIX compliant systems.
	setlocale(LC_NUMERIC, "");
	struct lconv *ptrLocale = localeconv();
	ptrLocale->decimal_point = ".";
	ptrLocale->thousands_sep = "'";
	
	printf("\nThere are %'lu paths through the lattice.\n\n", numPaths(rows, cols));

	return EXIT_SUCCESS;
}

void printError(char* name)
{
	fprintf (stderr,"Usage: %s -h \n", name);
	fprintf (stderr,"Usage: %s <path to file> \n", name);
	exit (EXIT_FAILURE);
}


void printHelp()
{
    printf("\nProject Euler Program 15\n\n"
        "Starting in the top left corner of a 2×2 grid, and only being able to move to\n"
		"the right and down, there are exactly 6 routes to the bottom right corner.  How\n"
		"many such routes are there through a 20×20 grid?\n\n"
		"This problem can be solved as-is but you can optionally provide different numbers\n"
		"for the rows and columns to solve other grid sizes.\n\n");

    exit (EXIT_SUCCESS);
}

