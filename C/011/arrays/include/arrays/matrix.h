#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>

// Representation of a 2D array/matrix
struct _matrix
{
	unsigned int rows;
	unsigned int cols;
	int *values;
};
typedef struct _matrix Matrix2D;


// Pass in the address of a Matrix2D pointer, along with the number of
// rows and columns that the matrix will have, and this will allocate 
// the correct amount of storage.
void matrixInit(Matrix2D** m, unsigned int rows, unsigned int cols);

#endif
