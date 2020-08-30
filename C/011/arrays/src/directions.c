#include "arrays/arrays.h"


/* All of the following functions assume a square, 2D array.  The 
 * x-coordinate is the rows and the y-coordinate is the columns.  
 * (x, y) = (0, 0)  corresponds with array[0][0].
 * 
 * For x more positive means more "down".  For y more positive means
 * more "right".
 */
 
 
 
 /* No "limit" is needed as there is no x-coordinate more "up" than 
  * x = 0.
  */ 
bool canGoUp(Point p, size_t numDigits)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	
	/* Minus 2 required here since we start counting coordinates at 
	 * zero (that's 1 number) and also because the consecutive numbers
	 * are inclusive of the current position (that's the second
	 * number).
	 */
	if (p.x > (numDigits - 2))
		return true;
	
	return false;
}


// Need 'rows' here to prevent reading beyond the array boundary
bool canGoDown(Point p, size_t numDigits, size_t rows)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	if (p.x <= (rows - numDigits))
		return true;
	return false;
}


// Need 'columns' here to prevent reading beyond the array boundary
bool canGoRight(Point p, size_t numDigits, size_t columns)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	if (p.y <= (columns - numDigits))
		return true;
	return false;
}


// No limit needed here as nothing is more "left" than y = 0.
bool canGoLeft(Point p, size_t numDigits)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	
	/* Minus 2 required here since we start counting coordinates at 
	 * zero (that's 1 number) and also because the consecutive numbers
	 * are inclusive of the current position (that's the second
	 * number).
	 */
	if (p.y >= (numDigits - 2))
		return true;
	return false;
}


// diagonal up and left
bool canGoUpLeft(Point p, size_t numDigits)
{
	return canGoUp(p, numDigits) && canGoLeft(p, numDigits);
}


// diagonal up and right
bool canGoUpRight(Point p, size_t numDigits, size_t columns)
{
	return canGoUp(p, numDigits) && canGoRight(p, numDigits, columns);
}


// diagonal down left
bool canGoDownLeft(Point p, size_t numDigits, size_t rows)
{
	return canGoDown(p, numDigits, rows) && canGoLeft(p, numDigits);
}


// diagonal down right
bool canGoDownRight(Point p, size_t numDigits, size_t rows)
{
	return canGoDown(p, numDigits, rows) && canGoRight(p, numDigits, rows);
}
