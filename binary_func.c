#include "main.h"

/**
 * binary_func- Function that prints an unsigned number
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int binary_func(va_list arguments, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int h, y, d, sum;
	unsigned int a[32];
	int count;
	char z;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	h = va_arg(arguments, unsigned int);
	y = 2147483648; /* (2 ^ 31) to find this value*/
	a[0] = h / y;
	for (d = 1; d < 32; d++)
	{
		y /= 2;
		a[d] = (h / y) % 2;
	}
	for (d = 0, sum = 0, count = 0; d < 32; d++)
	{
		sum += a[d];
		if (sum || d == 31)
		{
			z = '0' + a[d];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

