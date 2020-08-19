#include "numPalindrome/palindrome.h"


void test(uint32_t);


int main()
{
	test(1);
	test(12);
	test(33);
	test(123);
	test(505);
	return EXIT_SUCCESS;
}


void test(uint32_t n)
{
	if (isPalindrome(n))
		printf("%u is palindromic\n", n);
	else
		printf("%u is not palindromic\n", n);
}
