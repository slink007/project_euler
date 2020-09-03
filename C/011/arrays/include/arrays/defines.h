#ifndef __DEFINES_H__
#define __DEFINES_H__

// Representation of a point within a 2D array/matrix
struct _point
{
	unsigned int x;  // x-coordinate
	unsigned int y;  // y-coordinate
};
typedef struct _point Point;


typedef enum
{
	up,
	down,
	left,
	right,
	upLeft,
	upRight,
	downLeft,
	downRight,
	directionLimit
}Direction;

#endif
