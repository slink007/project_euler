#ifndef __PRODUCTS_H__
#define __PRODUCTS_H__

#include <stdio.h>
#include "defines.h"
#include "matrix.h"


/* Functions which start at Point p on an array, move in the
 * indicated direction, calculate the product of the numbers,
 * and return that product.  All need the address of the array.
 *
 * None of these functions do boundary checks as it is assumed that the
 * appropriate "consecutive" function has already been called prior to calling
 * them.
 *
unsigned long prodUp(Matrix *m, Point p, unsigned int numDigits);
unsigned long prodDown(Matrix *m, Point p, unsigned int numDigits);
unsigned long prodRight(Matrix *m, Point p, unsigned int numDigits);
unsigned long prodLeft(Matrix *m, Point p, unsigned int numDigits);
*/
unsigned long product(Matrix *m, Point p, unsigned int numDigits, Direction d);

#endif
