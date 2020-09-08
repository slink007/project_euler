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
*/
unsigned int numPaths(unsigned int rows, unsigned int cols)
{
	if ( (rows == 0) || (cols == 0) )
		return 1;
	
	return numPaths(rows, cols - 1) + numPaths(rows - 1, cols);
}
