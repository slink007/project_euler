#ifndef __COLLATZ_H__
#define __COLLATZ_H__

#include <stdio.h>
#include <stdlib.h>

/* Returns a count of the number of terms once a Collatz number has
 * degraded down to 1.
 */
size_t collatz(size_t n);

#endif
