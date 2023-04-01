#include "main.h"

/**
 * octal_funct- Prints an unsigned number in octal notation
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int octal_funct(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	int w = BUFF_SIZE - 2;
	unsigned long int number = va_arg(arguments, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = cast_size_unsgnd(number, size);
	if (number == 0)
		buffer[w--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buffer[w--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[w--] = '0';
	w++;
	return (write_unsgnd_func(0, w, buffer, flags, width, precision, size));
}
