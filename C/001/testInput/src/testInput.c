#include "testInput/testInput.h"

bool isValid(int n1, int n2, int limit)
{
	// These are supposed to be natural numbers so no negative 
	// values allowed.
	if ( (n1 < 0) || (n2 < 0) || (limit < 0) )
		return false;
	
	if ( (n1 > limit) || (n2 > limit) )
		return false;
		
	return true;
}
