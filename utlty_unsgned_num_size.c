#include "main.h"

/**
 * cast_size_unsgnd- Function that casts a number to the specified size
 * @numbr: Number that is going to be casted
 * @size_u: Number determining the type to be casted
 *
 * Return: Casted value of the number
 */
long int cast_size_unsgnd(unsigned long int numbr, int size_u)
{
	if (size_u == S_LONG)
		return (numbr);
	else if (size_u == S_SHORT)
		return ((unsigned short)numbr);

	return ((unsigned int)numbr);
}
