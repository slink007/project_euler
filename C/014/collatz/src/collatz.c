#include "collatz/collatz.h"

#define SIZE 101
static size_t previous[SIZE] = {0};  // previous results from collatz()


size_t collatz(size_t n)
{
	size_t original = n;
	
	if (n == 0) return 0;

	size_t count = 1;
	while (n > 1)
	{
		if ( (n < SIZE) && previous[n] != 0)
		{
			count += previous[n];
			break;
		}
		
		if (n & 1)   // n is odd
		{
			n *= 3;
			n++;
		}
		else         // n is even
			n /= 2;
		count++;
	}
	
	if (original < SIZE && previous[original] == 0)
		previous[original] = count - 1;
		
	return count;
}
