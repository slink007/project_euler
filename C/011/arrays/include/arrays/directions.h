#ifndef __DIRECTIONS_H__
#define __DIRECTIONS_H__

#include "point.h"

/* Functions which return true if it is possible to achieve numDigits
 * of consecutive numbers, including the number at the current position,
 * when moving in the indicated direction. 
 */
bool canGoUp(Point p, unsigned int numDigits);
bool canGoDown(Point p, unsigned int numDigits, unsigned int rows);
bool canGoRight(Point p, unsigned int numDigits, unsigned int columns);
bool canGoLeft(Point p, unsigned int numDigits);
bool canGoUpLeft(Point p, unsigned int numDigits);
bool canGoUpRight(Point p, unsigned int numDigits, unsigned int columns);
bool canGoDownLeft(Point p, unsigned int numDigits, unsigned int rows);
bool canGoDownRight(Point p, unsigned int numDigits, unsigned int rows);


#endif

