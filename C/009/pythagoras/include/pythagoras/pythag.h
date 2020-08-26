#ifndef __PYTHAG_H__
#define __PYTHAG_H__

#include <stdio.h>
#include <stdint.h>

struct _triangle
{
	size_t a;  // shortest side of right triangle
	size_t b;  // mid-length side of right triangle
	size_t c;  // hypotenuse of the right triangle
};
typedef struct _triangle Triangle;


// Produces a triangle whose sides form a Pythagorean Triplet
Triangle nextPythagTriplet(void);


// Pass in a Triangle and this returns the product of the sides
size_t triangleProduct(Triangle t);


// Pass in a Triangle and this returns the perimeter
size_t trianglePerimeter(Triangle t);

#endif
