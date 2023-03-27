#include "main.h"

/**
  *print_float_with_flags-function to print the value of a float variable 
  *with optional flag characters.
  *@val: Float value to print.
  *@plus:Flag character to print a plus sign before positive values (if true).
  *@space:Flag character to print a space before positive values (if plus is false).
  *@hash:Flag character to print a decimal point and trailing zeros even if no digits follow (if true).
  *@precision: Number of digits to print after the decimal point (default is 6).
  */

void print_float_with_flags(float val, int plus, int space, int hash, int precision) 
{
	int i, digit;
	/*Check if value is positive or negative*/
	if (val < 0) 
	{
		printf("-");
		val = -val;
	} 
	else if (plus) 
	{
		printf("+");
	} 
	else if (space) 
	{
		printf(" ");
	}
    
    /*Print value with specified precision and flag characters*/
	printf("%.*f", precision, val);
	if (hash) 
	{
		printf(".");
        /* Print trailing zeros up to specified precision*/
		for (i = 0; i < precision; i++) 
		{
			val *= 10;
			digit = (int) val % 10;
			printf("%d", digit);
		}
	}
}
