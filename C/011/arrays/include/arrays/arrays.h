#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "matrix.h"
#include "defines.h"
#include "directions.h"
#include "products.h"


/* Return the largest possible product of "numDigits" consecutive 
 * numbers from a square, 2D array where each side is "size" units long.
 */
unsigned int adjacentProduct(Matrix *m, unsigned int numDigits);


#endif
