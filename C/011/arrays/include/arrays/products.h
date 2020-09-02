#ifndef __PRODUCTS_H__
#define __PRODUCTS_H__

#include "point.h"
#include "matrix.h"

/* Functions which start at Point p on an array, move in the
 * indicated direction, calculate the product of the numbers,
 * and return that product.  All need the address of the array.
 *
 * None of these functions do boundary checks as it is assumed that the
 * appropriate "canGo" function has already been called prior to calling
 * them.
 */
unsigned long prodUp(Matrix2D *m, Point p, unsigned int numDigits);
unsigned long prodDown(Matrix2D *m, Point p, unsigned int numDigits);
unsigned long prodRight(Matrix2D *m, Point p, unsigned int numDigits);



#endif
