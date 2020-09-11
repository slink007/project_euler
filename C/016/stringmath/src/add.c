#include "stringmath/add.h"

void getSum(char *line, char *sum)
{
	// strip off linefeed from the line
	line[strcspn(line, "\r\n")] = '\0';
	
	int sumLen = strlen(sum) - 1;    // -1 so as to not read past end of array
	int carry = 0;
	int lineLen = strlen(line) - 1;  // -1 so as to not read past end of array
	int offset = sumLen - lineLen;
	
	// handle all digits from the line
	while (lineLen >= 0)
	{
		int temp = (line[lineLen] - '0') + (sum[lineLen + offset] - '0') + carry;
		
		if (temp > 9)
		{
			temp -= 10;
			carry = 1;
		}
		else carry = 0;
		
		sum[lineLen + offset] = (char)temp + '0';
		lineLen--;
		sumLen--;
	}
	
	// handle extra digits which may result from adding
	while ( (sumLen >= 0) && (carry == 1) )
	{
		int temp = (sum[sumLen] - '0') + carry;
		
		if (temp > 9)
		{
			temp -= 10;
			carry = 1;
		}
		else carry = 0;
		
		sum[sumLen] = (char)temp + '0';
		sumLen--;
	}
}