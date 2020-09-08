#ifndef __PATHS_H__
#define __PATHS_H__

/* Returns the number of paths through grid of size rows x cols.  The path
   begins at the upper-left corner and ends at the bottom-right corner.
   Only valid moves are down and right.
*/
unsigned int numPaths(unsigned int rows, unsigned int cols);

#endif