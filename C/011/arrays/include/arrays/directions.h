#ifndef __DIRECTIONS_H__
#define __DIRECTIONS_H__

#include "defines.h"
#include "matrix.h"


/* Functions which return true if it is possible to achieve numDigits
 * of consecutive numbers, including the number at the current position,
 * when moving in the indicated direction. 
 *
bool consecutiveUp(Point p, unsigned int numDigits);
bool consecutiveDown(Point p, unsigned int numDigits, unsigned int rows);
bool consecutiveRight(Point p, unsigned int numDigits, unsigned int columns);
bool consecutiveLeft(Point p, unsigned int numDigits);
bool consecutiveUpLeft(Point p, unsigned int numDigits);
bool consecutiveUpRight(Point p, unsigned int numDigits, unsigned int columns);
bool consecutiveDownLeft(Point p, unsigned int numDigits, unsigned int rows);
bool consecutiveDownRight(Point p, unsigned int numDigits, unsigned int rows);
*/

/*Return true if we can get 'numDigits' consecutive numbers in Matrix m
 * if we start at Point p and move in Direction d
 */
bool consecutive(unsigned int numDigits, Direction d, Point p, Matrix *m);

#endif

