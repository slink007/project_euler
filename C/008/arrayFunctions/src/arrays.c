#include "arrayFunctions/arrays.h"



size_t adjProduct(uint32_t n_adjacent, uint8_t* array, uint32_t length)
{
	size_t product = 1, maxProduct = 0;
	
	// select the starting point for multiplication
	for (size_t i = 0; i <= (length - n_adjacent); i++)
	{
		product = 1;
		
		// multiply n_adjacent numbers
		for (size_t j = i; j < i + n_adjacent; j++)
			//product *= array[j];
			product *= *(array + j);
		
		if (product > maxProduct)
			maxProduct = product;
	}
	
	return maxProduct;
}
