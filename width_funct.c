
#include "main.h"

/**
 * width_func-function that calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @w: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width required in printing
 */
int width_func(const char *format, int *w, va_list list)
{
	int curre_i;
	int _width = 0;

	for (curre_i = *w + 1; format[curre_i] != '\0'; curre_i++)
	{
		if (char_is_digit(format[curre_i]))
		{
			_width *= 10;
			_width += format[curre_i] - '0';
		}
		else if (format[curre_i] == '*')
		{
			curre_i++;
			_width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*w = curre_i - 1;

	return (_width);
}
