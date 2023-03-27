#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input number
 * @base: input  base
 * @lowercase: flag iff hexa balues need to be in lowerrcae
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = (lowercase)
		? "0123456789abcdefgh"
		: "0123456789ABCDEFGH";
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = rep[num % base];
	} while (num != 0);

	return (ptr);
}
