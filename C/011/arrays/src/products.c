#include "arrays/arrays.h"
#include <stdio.h>

/*
size_t prodUp(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t offset = 0;
	
	do
	{
		p.x -= offset;  // decrement since more negative == more "up"
		product *= (array)[p.x][p.y];
		offset++;  
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodDown(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t offset = 0;
	
	do
	{
		p.x += offset;  // increment since more positive == more "down"
		product *= (array)[p.x][p.y];
		offset++;  
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodLeft(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t offset = 0;
	
	do
	{
		p.y -= offset;  // decrement since more negative == more "left"
		product *= (array)[p.x][p.y];
		offset++;
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodRight(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t offset = 0;
	
	do
	{
		p.y += offset;  // increment since more positive == more "right"
		product *= (array)[p.x][p.y];
		offset++;
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodUpLeft(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t xOffset = 0;
	size_t yOffset = 0;
	
	do
	{
		p.x -= xOffset;  // decrement since more negative == more "up"
		p.y -= yOffset;  // decrement since more negative == more "left"
		product *= (array)[p.x][p.y];
		xOffset++;
		yOffset++;
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodUpRight(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t xOffset = 0;
	size_t yOffset = 0;
	
	do
	{
		p.x -= xOffset;  // decrement since more negative == more "up"
		p.y += yOffset;  // increment since more positive == more "right"
		product *= (array)[p.x][p.y];
		xOffset++;
		yOffset++;
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodDownLeft(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t xOffset = 0;
	size_t yOffset = 0;
	
	do
	{
		p.x += xOffset;  // increment since more positive == more "down"
		p.y -= yOffset;  // decrement since more negative == more "left"
		product *= (array)[p.x][p.y];
		xOffset++;
		yOffset++;
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t prodDownRight(const uint8_t array[][20], Point p, size_t numDigits)
{
	size_t product = 1;
	size_t xOffset = 0;
	size_t yOffset = 0;
	
	do
	{
		p.x += xOffset;  // increment since more positive == more "down"
		p.y += yOffset;  // increment since more positive == more "right"
		product *= (array)[p.x][p.y];
		xOffset++;
		yOffset++;
		numDigits--;
	} while ( numDigits > 0 );
	
	return product;
}


size_t adjacentProduct(const uint8_t array[][20], size_t size, size_t numDigits)
{
	size_t product = 1;
	size_t maxProduct = 1;
	Point p;
	
	for (size_t rows = 0; rows < size; rows++)
	{
		p.x = rows;
		for (size_t columns = 0; columns < size; columns++)
		{
			p.y = columns;
			
			// try to go up
			if ( canGoUp(p, numDigits) )
			{
				product = prodUp(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
				
			// try to go down
			if ( canGoDown(p, numDigits, size) )
			{
				product = prodDown(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		
			// try to go left
			if ( canGoLeft(p, numDigits) )
			{
				product = prodLeft(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		
			// try to go right
			if ( canGoRight(p, numDigits, size) )
			{
				product = prodRight(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		
			// try to go up-left diagonal
			if ( canGoUpLeft(p, numDigits) )
			{
				product = prodUpLeft(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		
			// try to go down-left diagonal
			if ( canGoDownLeft(p, numDigits, size) )
			{
				product = prodDownLeft(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		
			// try to go down-right diagonal
			if ( canGoDownRight(p, numDigits, size) )
			{
				product = prodDownRight(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		
			// try to go up-right diagonal
			if ( canGoUpRight(p, numDigits, size) )
			{
				product = prodUpRight(array, p, numDigits);
				if (product > maxProduct)
					maxProduct = product;
			}
		}
	}
	
	return product;
}
*/
