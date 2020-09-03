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
typedef struct _matrix Matrix;


// Pass in the address of a Matrix pointer, along with the number of
// rows and columns that the matrix will have, and this will allocate 
// the correct amount of storage.
void matrixInit(Matrix** m, unsigned int rows, unsigned int cols);


// Pass in a pointer to a Matrix and this will print out the contents
// of the matrix.
void printMatrix(const Matrix *m);


// Pass in a Matrix pointer, and a file pointer, and this will 
// open the file, read the data, and populate it into the matrix.
// Failure to open the file will result in the program terminating.
void fillData(Matrix *m, FILE *f);

#endif
