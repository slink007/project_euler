#ifndef __ADD_H__
#define __ADD_H__

#include <string.h>


/* The 'line' string contains some positive integer represented as a string.
 * The 'sum' string contains some positive integer represented as a string.
 * It is up to the caller to ensure that sum is long enough to hold the result
 *     of adding it and the line together.
 * After calling this function 'sum' will contain the sum of whatever 'sum'
 * held prior to this and the contents of 'line'.
 */
void getSum(char *line, char *sum);

#endif
