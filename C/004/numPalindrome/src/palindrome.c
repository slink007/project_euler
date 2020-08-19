#include "numPalindrome/palindrome.h"


bool isPalindrome(uint32_t number)
{
	uint32_t length;

	// how many digits in the number
	length = snprintf(NULL, 0, "%u", number);

	// single digit numbers are automatically palindromic
	if (length == 1)
		return true;

	char * p = NULL;
	p = malloc( (length + 1) * sizeof(char) );
	bool result = true;	

	if(p)
	{
		snprintf(p, length + 1, "%u", number);
		char * start = p;
		char * end = p + (length - 1);

		while (end > start)
		{
			if ( *(start) != *(end) )
			{
				result = false;
				break;
			}
			else
			{
				start++;
				end--;
			}
		}
	}
	else
	{
		fprintf(stderr, "Not enough memory\n");
		exit (EXIT_FAILURE);
	}
	
	free(p);
	return result;
}
