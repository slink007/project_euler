/* Problem Statement:
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which
 * a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pythagoras/pythag.h"

#define LIMIT 1000

int main(int argc, char ** argv)
{
	size_t sum = 0;
	size_t limit = LIMIT;
	Triangle t;

	do
	{
		t = nextPythagTriplet();
		sum = trianglePerimeter(t);
	} while (sum != limit);

	size_t product = triangleProduct(t);

	printf("\n%zu, %zu, and %zu make up a Pythagorean triplet whose sum is %zu and "
		"whose product is %zu\n\n", t.a, t.b, t.c, sum, product);

	return EXIT_SUCCESS;
}
