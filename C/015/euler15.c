/* Project Euler Program 15
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20×20 grid?
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paths/paths.h"

#define ROWS 20
#define COLS 20

void printError(char* name);
void printHelp();
unsigned int numPaths(unsigned int rows, unsigned int cols);

int main(int argc, char ** argv)
{
	unsigned int rows = ROWS;
	unsigned int cols = COLS;
	
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
			rows = (unsigned int)tempRow;
			cols = (unsigned int)tempCol;
		}
	}
	
	printf("\nThere are %u paths through the lattice\n\n", numPaths(rows, cols));
	
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
		"many such routes are there through a 20×20 grid?\n\n");

    exit (EXIT_SUCCESS);
}


/* Imagine a grid where increasing 'x' values mean moving left from the origin
 * and increasing 'y' values mean moving up from the origin.  If we have 2
 * rows and 2 columns on this grid the furthest point from the origin is at 
 * (2, 2).  
 *
 * If you can only move right or down there are 6 paths from this point back to
 * the origin.  If you move right one point to (1, 2) and down to (2, 1), and 
 * then retry the experiment, you find that each of those points has 3 paths back
 * to the origin.  So the paths from (2, 2) are equal to the sum of the paths from
 * (2, 1) and (1, 2).  Experimenting with other grid sizes, and non-square grid
 * shapes, shows that the relationship remains true.
 *
 * P(x, y) = P(x, y - 1) + P(x - 1, y)
*/
unsigned int numPaths(unsigned int rows, unsigned int cols)
{
	if ( (rows == 0) || (cols == 0) )
		return 1;
	
	return numPaths(rows, cols - 1) + numPaths(rows - 1, cols);
}