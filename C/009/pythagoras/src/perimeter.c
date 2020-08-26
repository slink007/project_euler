#include "pythagoras/pythag.h"

size_t trianglePerimeter(Triangle t)
{
	size_t sum = 0;

	sum += t.a;
	sum += t.b;
	sum += t.c;

	return sum;
}

