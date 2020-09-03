#include "arrays/arrays.h"


/* Helper functions for determining the ability to achieve a certain
 * number of consecutive numbers in a Matrix.  The x-coordinate is the 
 * rows and the y-coordinate is the columns.  (x, y) = (0, 0)  
 * corresponds with array[0][0].  For x more positive means more "down".
 * For y more positive means more "right".
 */
 
 
 
 /* No "limit" is needed as there is no x-coordinate more "up" than 
  * x = 0.
  */ 
bool consecutiveUp(Point p, unsigned int numDigits)
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
bool consecutiveDown(Point p, unsigned int numDigits, unsigned int rows)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	if (p.x <= (rows - numDigits))
		return true;
	return false;
}


// Need 'columns' here to prevent reading beyond the array boundary
bool consecutiveRight(Point p, unsigned int numDigits, unsigned int columns)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	if (p.y <= (columns - numDigits))
		return true;
	return false;
}


// No limit needed here as nothing is more "left" than y = 0.
bool consecutiveLeft(Point p, unsigned int numDigits)
{
	if (numDigits == 0) return false; // 0 consecutive numbers is invalid
	if (numDigits == 1) return true;  // always possible for 1 number
	
	/* Minus 2 required here since we start counting coordinates at 
	 * zero (that's 1 number) and also because the consecutive numbers
	 * are inclusive of the current position (that's the second
	 * number).
	 */
	if (p.y >= (numDigits - 1))  // was 2
		return true;
	return false;
}


bool consecutiveUpLeft(Point p, unsigned int numDigits)
{
	return consecutiveUp(p, numDigits) && consecutiveLeft(p, numDigits);
}


bool consecutiveUpRight(Point p, unsigned int numDigits, unsigned int columns)
{
	return consecutiveUp(p, numDigits) && consecutiveRight(p, numDigits, columns);
}


bool consecutiveDownLeft(Point p, unsigned int numDigits, unsigned int rows)
{
	return consecutiveDown(p, numDigits, rows) && consecutiveLeft(p, numDigits);
}


bool consecutiveDownRight(Point p, unsigned int numDigits, unsigned int rows)
{
	return consecutiveDown(p, numDigits, rows) && consecutiveRight(p, numDigits, rows);
}


bool consecutive(unsigned int numDigits, Direction d, Point p, Matrix *m)
{
	switch (d)
	{
		case up:
			return consecutiveUp(p, numDigits);
			break;
		case down:
			return consecutiveDown(p, numDigits, m->rows);
			break;
		case left:
			return consecutiveLeft(p, numDigits);
			break;
		case right:
			return consecutiveRight(p, numDigits, m->cols);
			break;
		case upRight:
			return consecutiveUpRight(p, numDigits, m->cols);
			break;
		case upLeft:
			return consecutiveUpLeft(p, numDigits);
			break;
		case downRight:
			return consecutiveDownRight(p, numDigits, m->rows);
			break;
		case downLeft:
			return consecutiveDownLeft(p, numDigits, m->rows);
			break;
		default:
			return false;
	}
}
