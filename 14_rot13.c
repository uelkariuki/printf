#include "main.h"

/**
 * rot13 - Function that prints a string in rot13.
 * @arguments: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */
int rot13(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	char c;
	char *str;
	unsigned int a, b;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(arguments, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(nil)";
	for (a = 0; str[a]; a++)
	{
		for (b = 0; in[b]; b++)
		{
			if (in[b] == str[a])
			{
				c = out[b];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!in[b])
		{
			c = str[a];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
