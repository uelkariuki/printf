#include "main.h"

/**
  *print_number- This function takes an unsigned integer number and a
  *conversion specifier character as input and prints the number in the
  * desired format based on the specifier.
  *
  *@num: The unsigned integer number to be printed
  *@spec: The conversion specifier character ('u', 'o', 'x', or 'X')
  *Return: None
 */

void print_number(unsigned int num, char spec)
{
	switch (spec)
	{
		case 'u': /*if specifier is 'u', print the number in decimal format*/
			printf("%u", num);
			break;
		case 'o':
			printf("%o", num);
			break;
		case 'x':
			printf("%x", num);
			break;
		case 'X':/*print the number in uppercase hexadecimal format*/
			printf("%X", num);
			break;
		default:
			printf("Invalid specifier");
			break;
	}
}

