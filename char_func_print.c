#include "main.h"

/**
 *print_char -function to print from int to char.
 *@list: va_list.
 *
 * Return: 1
 */
int print_char(va_list list)
{
	int aux;

	aux = va_arg(list, int);

	putchar(aux);

	return (1);
}
