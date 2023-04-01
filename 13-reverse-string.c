#include "main.h"

/**
 *reverse_string- Function that prints a string reversed
 *@arguments: List of arguments
 *@buffer: Buffer array to handle print
 *@flags:  Calculates active flags
 *@width: width required
 *@precision: Precision specification
 *@size: Size specifier
 *Return: Numbers of chars printed
 */

int reverse_string(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int x, count = 0;
	char b;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(arguments, char *);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}

	for (x = 0; str[x]; x++)
		;

	for (x = x - 1; x >= 0; x--)
	{
		b = str[x];

		write(1, &b, 1);
		count++;
	}
	return (count);
}

