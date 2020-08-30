#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


// Representation of a 2D array/matrix
struct _matrix
{
	uint8_t rows;
	uint8_t cols;
	uint8_t *values;
};
typedef struct _matrix Matrix2D;


// Representation of a point within a 2D array/matrix
struct _point
{
	size_t x;  // x-coordinate
	size_t y;  // y-coordinate
};
typedef struct _point Point;


/* Functions which return true if it is possible to achieve numDigits
 * of consecutive numbers, including the number at the current position,
 * when moving in the indicated direction. 
 */
bool canGoUp(Point p, size_t numDigits);
bool canGoDown(Point p, size_t numDigits, size_t rows);
bool canGoRight(Point p, size_t numDigits, size_t columns);
bool canGoLeft(Point p, size_t numDigits);
bool canGoUpLeft(Point p, size_t numDigits);
bool canGoUpRight(Point p, size_t numDigits, size_t columns);
bool canGoDownLeft(Point p, size_t numDigits, size_t rows);
bool canGoDownRight(Point p, size_t numDigits, size_t rows);


/* Functions which start at Point p on an array, move in the
 * indicated direction, calculate the product of the numbers,
 * and return that product.  All need the address of the array.
 *
 * None of these functions do boundary checks as it is assumed that the
 * appropriate "canGo" function has already been called prior to calling
 * them.
 */
/*size_t prodUp(uint8_t array[size][size], size_t size, Point p, size_t numDigits);
size_t prodDown(const uint8_t array[][20], Point p, size_t numDigits);
size_t prodLeft(const uint8_t array[][20], Point p, size_t numDigits);
size_t prodRight(const uint8_t array[][20], Point p, size_t numDigits);
size_t prodUpLeft(const uint8_t array[][20], Point p, size_t numDigits);
size_t prodUpRight(const uint8_t array[][20], Point p, size_t numDigits);
size_t prodDownLeft(const uint8_t array[][20], Point p, size_t numDigits);
size_t prodDownRight(const uint8_t array[][20], Point p, size_t numDigits);
*/

/* Return the largest possible product of "numDigits" consecutive 
 * numbers from a square, 2D array where each side is "size" units long.
 */
//size_t adjacentProduct(const uint8_t array[][20], size_t size, size_t numDigits);


#endif
