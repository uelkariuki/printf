#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
  *_printf- function that produces output according to a format.
  *@format: is a character string. The format string is composed of
  *         zero or more directives
  *Return:  the number of characters printed (excluding the null byte used
  *         to end output to strings)
  *
  */

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
					count = count + printf("%d", va_arg(args, int));
					break;
				case 'i':
					count = count + printf("%i", va_arg(args, int));
					break;
				default:
					break;
			}
		}
		else
		{
			count = count + putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
