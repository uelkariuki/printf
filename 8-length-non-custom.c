#include <stdio.h>

/**
  *print_integer_with_length_modifier-Custom function to print the value 
  *  of an integer variable with optional length modifiers.
  *@val:Integer value to print.
  *@length Length modifier character (optional).
  *@specifier Conversion specifier character (one of d, i, u, o, x, X).
  */

void print_integer_with_length_modifier(int val, char length, char specifier) 
{
	switch (length) 
	{
		case 'h':
			if (specifier == 'd' || specifier == 'i') 
			{
				printf("%hd", (short) val);
			} 
			else if 
				(specifier == 'u' || specifier == 'o' || specifier == 'x' 
				 || specifier == 'X') 
				{
					printf("%hu", (unsigned short) val);
				}
			break;
		case 'l':
			if (specifier == 'd' || specifier == 'i') 
			{
				printf("%ld", (long) val);
			} 
			else if 
				(specifier == 'u' || specifier == 'o' || specifier == 'x' 
				 || specifier == 'X') 
				{
					printf("%lu", (unsigned long) val);
				}
			break;
		default:
			printf("%d", val);
			break;
	}
}
