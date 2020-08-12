#include <stdlib.h>
#include "naturalSum/limitSum.h"


/*
	Return the sum of all natural numbers which are multiples of n1 or n2
	and which are less than limit.
*/
unsigned int limitSum(unsigned int n1, unsigned int n2, unsigned int limit)
{
	unsigned int total = 0;

	for(unsigned int i = n1; i < limit; i++)
	{
		if( (i % n1 == 0) || (i % n2 == 0) )
			total += i;
	}

	return total;
}
