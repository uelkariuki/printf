#include "main.h"

/**
 * hexa_up-function that prints an unsigned number in upper hexadecimal
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_up(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	return (hex_funct(arguments, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}
