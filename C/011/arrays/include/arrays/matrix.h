#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


// Pass in a pointer to a Matrix2D and this will print out the contents
// of the matrix.
void printMatrix(const Matrix2D *m);


// Pass in a Matrix2D pointer, and a file pointer, and this will 
// open the file, read the data, and populate it into the matrix.
// Failure to open the file will result in the program terminating.
void fillData(Matrix2D *m, FILE *f);

#endif
