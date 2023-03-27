#include "main.h"
/**
  *print_with_custom_specifiers- function that handles the b custom specifier
  *                        that converts an unsigned int argument to binary
  *@format: the character string composed of zero of more directives
  *
  */
void print_with_custom_specifiers(const char *format, ...)
{
	va_list args;
	const char *p;
	unsigned int arg;
	unsigned int mask;

	va_start(args, format);

	for (p = format; *p != '\0'; ++p)
	{
		if (*p == '%' && (*p + 1) == 'b')
		{
			arg = va_arg(args, unsigned int);
			mask = 1u << (sizeof(unsigned int) * 8 - 1);
			while (mask > 0)
			{
				printf("%d", (arg & mask) != 0);
				mask >>= 1;
			}
			++p;

		}
		else
		{
			putchar(*p);
		}

	}
	va_end(args);

}
