#include "main.h"

/**
 *cast_number_to_size- function to  cast a number to specified size
 *@numbr: Number to be casted.
 *@size_n: Number to determine the type to be casted.
 *
 *Return: Casted value of number
 */
long int cast_number_to_size(long int numbr, int size_n)
{
	if (size_n == S_LONG)
	{
		return (numbr);
	}
	else if (size_n == S_SHORT)
	{
		return ((short)numbr);
	}

	return ((int)numbr);
}
