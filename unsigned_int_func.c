#include "main.h"

/**
 * unsigned_int_func - Funtion that prints an unsigned number
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int unsigned_int_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	int v = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arguments, unsigned long int);

	number = cast_size_unsgnd(number, size);
	if (number == 0)
		buffer[v--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[v--] = (number % 10) + '0';
		number /= 10;
	}
	v++;
	return (write_unsgnd_func(0, v, buffer, flags, width,
				precision, size));
}
