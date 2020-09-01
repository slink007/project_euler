#include "arrays/matrix.h"


void matrixInit(Matrix2D** m, unsigned int rows, unsigned int cols)
{
	(*m)->rows = rows;
	(*m)->cols = cols;
	(*m)->values = malloc((*m)->rows * (*m)->cols * sizeof(int));
}
