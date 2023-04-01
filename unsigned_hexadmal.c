#include "main.h"

/**
 * hexadmal - Function that Prints an unsigned number in hexadecimal notation
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags needed
 * @width: get width required
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexadmal(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	return (hex_funct(arguments, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}
