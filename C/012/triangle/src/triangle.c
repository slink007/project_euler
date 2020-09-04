#include "triangle/triangle.h"


/* Triangle numbers are made by adding consecutive integers.
 * 1
 * 3 (1 + 2)
 * 6 (1 + 2 + 3)
 * Instead of adding integers we can generate a triangle number with 
 * the formula of t = n(n+1)/2.
 */
size_t nextTriangle(void)
{
	static size_t n = 1;
	
	size_t triangle = (size_t)(n * (n + 1) / 2);
	n++;
	
	return triangle;
}
