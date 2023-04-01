#include "main.h"

/**
 * precision_funct- Function that calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @x: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: The Precision needed
 */
int precision_funct(const char *format, int *x, va_list list)
{
	int curr_i = *x + 1;
	int precise = -1;

	if (format[curr_i] != '.')
		return (precise);

	precise = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (char_is_digit(format[curr_i]))
		{
			precise *= 10;
			precise += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precise = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*x = curr_i - 1;

	return (precise);
}

