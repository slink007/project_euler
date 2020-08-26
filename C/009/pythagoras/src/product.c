#include "pythagoras/pythag.h"

size_t triangleProduct(Triangle t)
{
	size_t product = 1;

	product *= t.a;
	product *= t.b;
	product *= t.c;

	return product;
}

