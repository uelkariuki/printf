#include "main.h"

/**
 * find_flag - Turns on flags if _printf finds a
 * flag modifier in the format string.
 *
 * @s: character that holds the flag specifier.
 * @f: pointer to the struct flags in which we turn the flags on.
 *
 * Return: 1 if flag has been turned on and 0 if otherwise.
 *
 */

int find_flag(char s, flag_t *f)
{
	int i = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}
	return (i);
}
