#include "main.h"

/**
 * hex_funct- Prints a hexadecimal number in lower or upper
 * @arguments: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags present
 * @flag_ch: Calculates active flags present
 * @width: get width present
 * @precision: Precision specification
 * @size: Size specifier that is required
 * @size: Size specification
 * Return: Number of characters printed
 */
int hex_funct(va_list arguments, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int h = BUFF_SIZE - 2;
	unsigned long int numbr = va_arg(arguments, unsigned long int);
	unsigned long int init_num = numbr;

	UNUSED(width);

	numbr = cast_size_unsgnd(numbr, size);

	if (numbr == 0)
		buffer[h--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (numbr > 0)
	{
		buffer[h--] = map_to[numbr % 16];
		numbr /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[h--] = flag_ch;
		buffer[h--] = '0';
	}
	h++;

	return (write_unsgnd_func(0, h, buffer, flags, width, precision, size));
}
