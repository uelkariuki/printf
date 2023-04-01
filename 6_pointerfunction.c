#include "main.h"

/**
 * pointer_func- Function that Prints the value of a pointer variable
 * @arguments: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int pointer_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size)
{
	char _c = 0, pd = ' ';
	int y = BUFF_SIZE - 2, length = 2, pd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(arguments, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';

	UNUSED(precision);
	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[y--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pd = '0';
	if (flags & F_PLUS)
		_c = '+', length++;
	else if (flags & F_SPACE)
		_c = ' ', length++;
	y++;
	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer_func(buffer, y, length,
				width, flags, pd, _c, pd_start));
}
