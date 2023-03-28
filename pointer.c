#include "main.h"

int _strcmp(char *, char *);

/**
 *print_pointer - function to Print a number in hexadecimal format
 *@list: Number to print
 *
 *Return: Length of the number
 */
int print_pointer(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned long int), 16);

	if (!_strcmp(p_buff, "0"))
		return (print("(nil)"));

	size = print("0x");

	if (!_strcmp(p_buff, "-1"))
		size += print("ffffffffffffffff");
	else
		size += print(p_buff);

	return (size);
}

/**
 *_strcmp - function to Compare two strings
 *@s1: String 1
 *@s2: String 2
 *Return: Integer
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
	}

	return (0);
}

