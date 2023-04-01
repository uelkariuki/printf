#include "main.h"

/**
 * handle_printing_funct- Function that prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments that will be printed.
 * @ind: ind.
 * @buffer: Buffer array made to handle printing
 * @flags: Calculates active flags present
 * @width: get width present.
 * @precision: Precision specification for printing
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_printing_funct(const char *fmt, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size)
{
	int x, unknow_len = 0, the_printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', char_func}, {'s', string_func}, {'%', percent_specifier},
		{'i', int_function}, {'d', int_function}, {'b', binary_func},
		{'u', unsigned_int_func}, {'o', octal_funct}, {'x', hexadmal},
		{'X', hexa_up}, {'p', pointer_func}, {'S', non_printable},
		{'r', reverse_string}, {'R', rot13}, {'\0', NULL}
	};
	for (x = 0; fmt_types[x].fmt != '\0'; x++)
		if (fmt[*ind] == fmt_types[x].fmt)
			return (fmt_types[x].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[x].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (the_printed_chars);
}

