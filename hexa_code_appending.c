#include "main.h"

/**
 * hexa_code_appending- Append ascci in hexadecimal code to buffer
 * @buffer: Array of characters (temp store).
 * @x: Index at which appending will start
 * @_ascii_code: ASCCI CODE.
 * Return: 3
 */
int hexa_code_appending(char _ascii_code, char buffer[], int x)
{
	char mapping_to[] = "0123456789ABCDEF";
	/* The hexa format code will always be  2 digits long */
	if (_ascii_code < 0)
		_ascii_code *= -1;

	buffer[x++] = '\\';
	buffer[x++] = 'x';

	buffer[x++] = mapping_to[_ascii_code / 16];
	buffer[x] = mapping_to[_ascii_code % 16];

	return (3);
}
