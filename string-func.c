#include "main.h"

/**
 *print_string - function to print string
 *@list: list.
 *
 *Return: String length.
 */

int print_string(va_list list)
{
	char *str;
	int p_len;

	str = va_arg(list, char*);
	p_len = print((str != NULL) ? str : "(null)");

	return (p_len);
}

