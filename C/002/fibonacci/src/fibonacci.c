#include <stdio.h>
#include <stdlib.h>
#include "fibonacci/fibonacci.h"


fibNum firstFibonacci()
{
	fibNum temp;

	temp.x = 0;
	temp.y = 1;
	temp.num = 1;
	temp.pos = 1;

	return temp;
}


void nextFib(fibNum * f)
{
	f->x = f->y;
	f->y = f->num;

	if ( (f->x + f->y) < f->num )
	{
		fprintf(stderr,"Number too high resulting in overflow\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		f->num = f->x + f->y;
		f->pos += 1;
	}
}

