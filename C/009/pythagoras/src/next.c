#include "pythagoras/pythag.h"

/* A Pythagorean Triplet is formed when we have 3 whole numbers (a, b, and c)
 * such that c > b > a and c^2 = a^2 + b^2.
 *
 * It turns out that we can calculate valid values for a, b, and c based off of
 * 2 other whole numbers (m, n) where m > n.  The formulas are:
 * a = m^2 - n^2
 * b = 2mn
 * c = m^2 + n^2
 *
 * This function will act as a "triplet generator" and with each successive call
 * it will increment n or m to produce larger triplets.
 */
Triangle nextPythagTriplet(void)
{
	static size_t m = 1;
	static size_t n = 0;

	if ( (n + 1) == m )
	{
		m++;
		n = 1;
	}
	else
		n++;

	Triangle t;
	t.a = (m * m) - (n * n);
	t.b = 2 * m * n;
	t.c = (m * m) + (n * n);

	return t;
}

