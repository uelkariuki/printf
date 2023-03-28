#include "main.h"

int is_lowercase(char);
char *string_to_upper(char *);

/**
 *print_hexadecimal_upp - function to Print a number in hexadecimal format
 *@list: Number to print
 *
 *Return: Length of the number
 */
int print_hexadecimal_upp(va_list list)
{
	char *p_buff;
	int size;

	p_buff = itoa(va_arg(list, unsigned int), 16);
	p_buff = string_to_upper(p_buff);

	size = print((p_buff != NULL) ? p_buff : "NULL");

	return (size);
}

/**
 *is_lowercase - Check if the character are in lowercase
 *@c: Character
 *Return: 1 or 0
 */
int is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 *string_to_upper - function to Change the string to uppercase
 *@s: String
 *Return: String uppercase
 */
char *string_to_upper(char *s)
{
	int a;

	for (a = 0; s[a] != '\0'; a++)
	{
		if (is_lowercase(s[a]))
		{
			s[a] = s[a] - 32;
		}
	}

	return (s);
}

