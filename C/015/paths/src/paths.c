#include "paths/paths.h"

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

unsigned int numPaths(unsigned int rows, unsigned int cols)
{
	if ( (rows == 0) || (cols == 0) )
		return 1;

	return numPaths(rows, cols - 1) + numPaths(rows - 1, cols);
}

This code works well for lattices with a size of 10 or less.  Even for ones
with a size of up to 15 it isn't too bad.  When you get to a size of 20 the
time to complete becomes far too long.  The reason is that you wind up doing
a lot of repetitive calculations and the number expands a lot with increases
in lattice size.
*/



unsigned long numPaths(unsigned long rows, unsigned long cols)
{
    unsigned long grid[rows + 1][cols + 1];

    // initialize with 1's along right and bottom
    for (unsigned long i = 0; i <= rows; i++)
        grid[i][cols] = 1;
    for (unsigned long j = 0; j <= cols; j++)
        grid[rows][j] = 1;


    for (long int i = rows - 1; i >= 0; i--)
        for (long int j = cols - 1; j >= 0; j--)
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];

    return grid[0][0];
}

/* This is no better than the last version in terms of performance but it
* compensates for that by being harder to follow.  :(

*/


/* Helper function for the next function.  Computes and returns the
 * factorial of 'n'. 
 */
/*unsigned long factorial(unsigned long n) {
	if (n == 0) return 1;
	return (n * factorial(n - 1));
}*/


/* This implements a combination of permutations to get the answer.
 * C(n, k) = n! / ( (n - k)! * k! )
 */
//unsigned long numPaths(unsigned long rows, unsigned long cols)
//{
	/* For any square or rectangular shaped lattice if you start off
	 * in the uppper left corner, and travel to the bottom right
	 * corner going only right or down, then there will always be
	 * rows + columns transitions needed to complete the journey.
	 */
	/*unsigned long moves = rows + cols;
	return (factorial(moves) / factorial(moves - rows)) / factorial(rows);
}*/
