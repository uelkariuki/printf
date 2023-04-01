#include "main.h"


/**
 * int_function- function that print an integer
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width needed.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int int_function(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int int_is_negative = 0;
	long int n = va_arg(arguments, long int);
	unsigned long int numb;

	n = cast_number_to_size(n, size);
	if (n == 0)
		buffer[x--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	numb = (unsigned long int)n;
	if (n < 0)
	{
		numb = (unsigned long int)((-1) * n);
		int_is_negative = 1;
	}
	while (numb > 0)
	{
		buffer[x--] = (numb % 10) + '0';
		numb /= 10;
	}
	x++;

	return (handle_write_number(int_is_negative, x, buffer, flags,
				width, precision, size));
}
