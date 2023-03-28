#include "main.h"

/**
 *print - function to print char.
 *@str: string.
 *
 *Return: string length.
 */

int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		putchar(str[i]);

	return (i);
}

