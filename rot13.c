#include "main.h"

/**
 *rot13 - function that encodes a string using rot13.
 *@s: String to enconde
 *Return: String encode
 */
int rot13(char *s)
{
	int a, b;
	char *normal, *rot13;

	normal = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (a = 0; s[a] != '\0'; a++)
	{
		for (b = 0; normal[b] != '\0'; b++)
		{
			if (s[a] == normal[b])
			{
				putchar(rot13[b]);
				break;
			}
		}

		if (!normal[b])
			putchar(s[a]);
	}
	return (a);
}

/**
 * print_rot - Prints the rot13'ed string
 * @list: String to encoded
 *
 * Return: Length of the string encoded
 **/
int print_rot(va_list list)
{
	char *p;
	int p_len;

	p = va_arg(list, char *);
	p_len = rot13((p != NULL) ? p : "(ahyy)");

	return (p_len);
}
