/* Project Euler Program 18
 * By starting at the top of the triangle below and moving to adjacent numbers
 * on the row below, the maximum total from top to bottom is 23.
 *
 *                     3
 *                    7 4
 *                   2 4 6
 *                  8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * Find the maximum total from top to bottom of the triangle below:
 *
 *                                75
 *                               95 64
 *                             17 47 82
 *                            18 35 87 10
 *                           20 04 82 47 65
 *                          19 01 23 75 03 34
 *                         88 02 77 73 07 63 67
 *                        99 65 04 28 06 16 70 92
 *                       41 41 26 56 83 40 80 70 33
 *                      41 48 72 33 47 32 37 16 94 29
 *                     53 71 44 65 25 43 91 52 97 51 14
 *                    70 11 33 28 77 73 17 78 39 68 17 57
 *                  91 71 52 38 17 14 91 43 58 50 27 29 48
 *                 63 66 04 68 89 53 67 30 73 16 69 87 40 31
 *                04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
 * 
 * Answer = 1074
*/


#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>


	/* Put the data into a 2D array and pad unused cells with -1.  Start at next
	 * to last row.  Find the greater sum of cell[i][j] + cell[i+1][j] and
	 * cell[i][j] + cell[i+1][j+1].  Put that sum into cell[i][j].  Ignore any
	 * cell with a -1 in it.  When all cells have been processed cell[0][0] will
	 * contain the maximum possible total. 
	*/
int main(int argc, char *argv[])
{
	int height = 15;
	int width = 15;
	int t[][15] = {
		{75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{95, 64, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{17, 47, 82, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{18, 35, 87, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{20,  4, 82, 47, 65, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{19,  1, 23, 75,  3, 34, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{88,  2, 77, 73,  7, 63, 67, -1, -1, -1, -1, -1, -1, -1, -1},
		{99, 65,  4, 28,  6, 16, 70, 92, -1, -1, -1, -1, -1, -1, -1},
		{41, 41, 26, 56, 83, 40, 80, 70, 33, -1, -1, -1, -1, -1, -1},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29, -1, -1, -1, -1, -1},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, -1, -1, -1, -1},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, -1, -1, -1},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, -1, -1},
		{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, -1},
		{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23},
	};
	
	for (int i = (height - 2); i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			if (t[i][j] != -1)
				t[i][j] += (t[i+1][j] > t[i+1][j+1]) ? 
				t[i+1][j] : t[i+1][j+1];
		}
	}
	
	printf("\nThe maximum total from top to bottom is %d\n\n", t[0][0]);
	
	return EXIT_SUCCESS;
}
