/* Project Euler Program 1
 * If we list all the natural numbers below 10 that are multiples of 3
 * or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "naturalSum/limitSum.h"

int main()
{
	unsigned int num1 = 3, num2 = 5, limit = 1000;

	printf("The sum of all the multiples of %d and %d below %d is %d\n", \
		num1, num2, limit, limitSum(num1, num2, limit));

	return 0;
}
