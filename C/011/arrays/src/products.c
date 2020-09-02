#include "arrays/point.h"
#include "arrays/matrix.h"
#include <stdio.h>

unsigned long prodUp(Matrix2D *m, Point p, unsigned int numDigits)
{
	unsigned int product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols));
		numDigits--;
		p.x -= 1;  // decrement since more negative == more "up"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodDown(Matrix2D *m, Point p, unsigned int numDigits)
{
	unsigned int product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols));
		numDigits--;
		p.x += 1;  // increment since more positive == more "down"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodRight(Matrix2D *m, Point p, unsigned int numDigits)
{
	unsigned int product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y += 1;  // increment since more positive == more "right"
	} while (numDigits > 0);
	
	return product;
}
