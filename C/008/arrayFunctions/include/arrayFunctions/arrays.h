#ifndef __ARRAYS_H__
#define __ARRAYS_H__

#include <stdlib.h>
#include <stdint.h>


/* Iterate through an array which is 'length' items long and looks for
 * 'n_adjacent' numbers.  Returns the largest product available from
 * those adjacent numbers.
 */
size_t adjProduct(uint32_t n_adjacent, uint8_t* array, uint32_t length);


#endif
