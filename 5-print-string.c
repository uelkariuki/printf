#include "main.h"

/**
 *print_string-function to print a string with non-printable characters in the format \xHH.
 *@str Pointer to the null-terminated string to print.
 */

void print_string(char* str)
{
	int i = 0;

	while (str[i] != '\0') 
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127) 
		{/* Check if the character is non-printable.*/
			printf("\\x%02X", (unsigned char)str[i]);/* Print the character in the format \xHH.*/
		} 
		else 
		{
			printf("%c", str[i]);/*Print the character as is.*/
		}
		i++;
	}
}

