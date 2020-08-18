#include "numPalindrome/palindrome.h"


bool isPalindrome(uint32_t number)
{
	int32_t length;

	// how many digits in the number
	length = snprintf(NULL, 0, "%u", number);

	//debug
	printf("%u contains %d digits\n", number, length);
	//debug
	
	return true;
}
