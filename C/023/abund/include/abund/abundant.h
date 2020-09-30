#ifndef __ABUNDANT_H__
#define __ABUNDANT_H__

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void addNumber(size_t n);

void freeNumbers();


// Returns true if 'n' is an abundant number.
bool isAbundant(size_t n);


// Finds the sum of all divisors of 'n', exluding 'n' itself, and
// returns that sum.
size_t sumOfDivisors(size_t n);


// Returns true if 'n' is not an abundant sum.  An abundant sum is the
// result of adding two abundant numbers together.
bool notAbundantSum(size_t n);


void testNumbersForAbundance();

#endif
