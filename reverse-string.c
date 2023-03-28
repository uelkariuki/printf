#include "main.h"

/**
 *print_rev_string - function to print a string in reverse
 *@list: List of arguments
 *
 *Return: Length of the string
 */
int  print_rev_string(va_list list)
{
	int a, size;
	const char *str;

	str = va_arg(list, const char *);

	size = strlen(str);

	for (a = size - 1; a >= 0; a--)
		putchar(str[a]);

	return (size);
}
