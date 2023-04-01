#include "main.h"

/**
 * non_printable - Prints ascii codes in hexa of non printable chars
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int non_printable(va_list arguments, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = 0, offset = 0;
	char *str = va_arg(arguments, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[x] != '\0')
	{
		if (char_is_printable(str[x]))
			buffer[x + offset] = str[x];
		else
			offset += hexa_code_appending(str[x], buffer, x + offset);

		x++;
	}

	buffer[x + offset] = '\0';

	return (write(1, buffer, x + offset));
}

