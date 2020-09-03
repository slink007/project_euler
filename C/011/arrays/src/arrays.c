#include "arrays/arrays.h"



unsigned int adjacentProduct(Matrix *m, unsigned int numDigits)
{
	unsigned int thisProduct = 1, maxProduct = 0;
	
	if (numDigits == 0)
		return 0;

	for (unsigned int rows = 0; rows < m->rows; rows++)
	{
		for (unsigned int cols = 0; cols < m->cols; cols++)
		{
			Point p;
			p.x = rows;
			p.y = cols;
			
			for (Direction d = up; d < directionLimit; d++)
			{
				if (consecutive(numDigits, d, p, m))
				{
					thisProduct = product(m, p, numDigits, d);
					if (thisProduct > maxProduct)
						maxProduct = thisProduct;
				}
			}
		}
	}
	
	return maxProduct;
}
