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


/* This code uses the upper-left corner of the lattice as the origin.  It 
 * works off of a grid where each cell contains the number of paths from that
 * cell to the end (again, only moving right or down).  It works from the end
 * back to the start and in this way avoids repetitive calculations.
 *
 * Not only does this not suffer the performance hit of the previous version it 
 * can solve a 20 x 20 lattice in less than a second.  It can also do up to a 
 * 25 x 25 lattice just as quickly.  I didn't try taking it any higher because
 * the solution at 25 x 25 is 126,410,606,437,752 we will soon run into limits on
 * how large a number unsigned long can handle.
 */
unsigned long numPaths(unsigned long rows, unsigned long cols)
{
    unsigned long grid[rows + 1][cols + 1];  // array of paths to the end 

    /* If we are located at any point along the bottom row, or on the right
	 * side then there is only 1 path to the end.
	 */
    for (unsigned long i = 0; i <= rows; i++)
        grid[i][cols] = 1;
    for (unsigned long j = 0; j <= cols; j++)
        grid[rows][j] = 1;

	/* Beginning at a point 1 row up from the bottom, and 1 column left of the
	 * right most edge, we start filling in the table.  Each cell contains the
	 * sum of the paths of the cell to the right of it and the cell below it.
	 */
    for (long int i = rows - 1; i >= 0; i--)
        for (long int j = cols - 1; j >= 0; j--)
            grid[i][j] = grid[i + 1][j] + grid[i][j + 1];

    return grid[0][0];
}
