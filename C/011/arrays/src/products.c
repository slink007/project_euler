#include "arrays/products.h"
#include <stdio.h>

unsigned long prodUp(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.x -= 1;  // decrement since more negative == more "up"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodDown(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.x += 1;  // increment since more positive == more "down"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodRight(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y += 1;  // increment since more positive == more "right"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodLeft(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y -= 1;  // decrement since more negative == more "left"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodUpLeft(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y -= 1;  // decrement since more negative == more "left"
		p.x -= 1;  // decrement since more negative == more "up"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodDownLeft(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y -= 1;  // decrement since more negative == more "left"
		p.x += 1;  // increment since more positive == more "down"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodUpRight(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y += 1;  // increment since more positive == more "right"
		p.x -= 1;  // decrement since more negative == more "up"
	} while (numDigits > 0);
	
	return product;
}


unsigned long prodDownRight(Matrix *m, Point p, unsigned int numDigits)
{
	unsigned long product = 1;
		
	do
	{
		product *= *(m->values + (p.x * m->cols) + p.y);
		numDigits--;
		p.y += 1;  // increment since more positive == more "right"
		p.x += 1;  // increment since more positive == more "down"
	} while (numDigits > 0);
	
	return product;
}


unsigned long product(Matrix *m, Point p, unsigned int numDigits, Direction d)
{
	switch (d)
	{
		case up:
			return prodUp(m, p, numDigits);
			break;
		case down:
			return prodDown(m, p, numDigits);
			break;
		case left:
			return prodLeft(m, p, numDigits);
			break;
		case right:
			return prodRight(m, p, numDigits);
			break;
		case upLeft:
			return prodUpLeft(m, p, numDigits);
			break;
		case upRight:
			return prodUpRight(m, p, numDigits);
			break;
		case downLeft:
			return prodDownLeft(m, p, numDigits);
			break;
		case downRight:
			return prodDownRight(m, p, numDigits);
			break;
		default:
			return 0;
	}
}
