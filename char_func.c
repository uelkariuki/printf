#include "main.h"


/**
 * print_char - Function that prints a char
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width required
 * @precision: Precision specification needed
 * @size: Size specifier
 * Return: Number of chars printed
 */
int char_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(arguments, int);

	return (handles_write_charac(c, buffer, flags, width, precision,
				size));
}
