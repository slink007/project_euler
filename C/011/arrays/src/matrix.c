#include "arrays/matrix.h"


void matrixInit(Matrix2D** m, unsigned int rows, unsigned int cols)
{
	(*m)->rows = rows;
	(*m)->cols = cols;
	(*m)->values = malloc((*m)->rows * (*m)->cols * sizeof(int));
}


void printMatrix(const Matrix2D *m)
{
	unsigned int count = 1;
	unsigned limit = (m->rows) * (m->cols);
	for (unsigned int j = 0; j < limit; j++)
	{
		if ( count < (m->cols) )
			printf("%2d, ", m->values[j]);
		else
		{
			printf("%2d\n", m->values[j]);
			count = 0;
		}
		count++;
	}
}


void fillData(Matrix2D *m, FILE *f)
{
	if (f == NULL)
	{
		fprintf(stderr, "Unable to open file\n");
		exit (EXIT_FAILURE);
	}
	
	// Read file into memory
	char *buffer = NULL;
	size_t bufsize = (m->rows) * (m->cols);
	//size_t charsRead;
	buffer = (char *)malloc(bufsize * sizeof(char));
	getline(&buffer, &bufsize, f);
	//printf("Read %zu characters from the file\n", charsRead);
	
	// Parse through memory looking for the data
	char *token = NULL;
	size_t i = 0;
	token = strtok(buffer, ",");
	while (token != NULL)
	{
		m->values[i] = atoi(token);  // save data to matrix
		i++;
		token = strtok(NULL, ",");
	}
	
	free(buffer);
}

