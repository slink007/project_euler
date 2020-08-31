#ifndef __MATRIX_H__
#define __MATRIX_H__

// Representation of a 2D array/matrix
struct _matrix
{
	unsigned int rows;
	unsigned int cols;
	int *values;
};
typedef struct _matrix Matrix2D;

#endif
