#include "main.h"

/**
 * flags_funct- Function that Calculates the active flags present
 * @format: Formatted string in which to print the arguments
 * @x: take a parameter.
 * Return: Flags:
 */
int flags_funct(const char *format, int *x)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, curre_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curre_i = *x + 1; format[curre_i] != '\0'; curre_i++)
	{
		for (a = 0; FLAGS_CH[a] != '\0'; a++)
			if (format[curre_i] == FLAGS_CH[a])
			{
				flags |= FLAGS_ARR[a];
				break;
			}

		if (FLAGS_CH[a] == 0)
			break;
	}

	*x = curre_i - 1;

	return (flags);
}
