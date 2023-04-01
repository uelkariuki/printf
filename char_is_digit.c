#include "main.h"

/**
 * char_is_digit - Function that checks if a character is a digit
 * @d: Character to be checked if it is a digit
 *
 * Return: 1 if c is a digit, 0 if not
 */
int char_is_digit(char d)
{
	if (d >= '0' && d <= '9')
		return (1);

	return (0);
}
