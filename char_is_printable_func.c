
#include "main.h"

/**
 * char_is_printable - Fucntion that determines if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int char_is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
