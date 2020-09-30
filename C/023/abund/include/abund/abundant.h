#ifndef __ABUNDANT_H__
#define __ABUNDANT_H__

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Returns true if 'n' is an abundant number.
bool isAbundant(size_t n);


// Finds the sum of all divisors of 'n', exluding 'n' itself, and
// returns that sum.
size_t sumOfDivisors(size_t n);


// Returns true if 'n' is not an abundant sum.  An abundant sum is the
// result of adding two abundant numbers together.
bool notAbundantSum(size_t n);


// Tests all positive integers from 1 to 20161 to determine if they are
// abundant or not.  Fills an array of booleans with the results.  The
// number under test serves as the index to the array.
void testNumbersForAbundance();

#endif
