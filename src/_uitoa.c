#include "main.h"
#include <stdio.h>

/**
 * Function that converts an unsigned integer to a string
*/

void _uitoa(unsigned int num, char s[]) {
	int i;

	i = 0;
	do{
		/*get the last digit and convert it to a char (be in char range) by adding 48 or '0'*/
		s[i++] = (num % 10) + '0';
	} while ((num /= 10) > 0);

	/* add a null terminating character at the end to make the string valid*/
	s[i] = '\0';
	reverse(s);
}

/*Testing the function
int main() {
	char str[30];
	unsigned int n = 3423423;
	_uitoa(n, str);
	write(1, str, strlen(str)); // prints '3423423'
}*/ 

