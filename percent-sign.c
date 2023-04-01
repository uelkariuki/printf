#include "main.h"

/**
 * percent_specifier- Function that prints a percent sign
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width needed.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int percent_specifier(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(arguments);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	return (write(1, "%%", 1));
}
