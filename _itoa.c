#include "main.h"
#include <stdio.h>

/**
 * Function that converts a signed integer to a string
*/

void _itoa(int num, char s[]) {
	int sign, i;

	/*make the num positive if it is negative*/
	if ((sign = num) < 0) {
		num = -num;
	}
	i = 0;
	do{
		/*get the last digit and convert it to a char (be in char range) by adding 48 or '0'*/
		s[i++] = (num % 10) + '0';
	} while ((num /= 10) > 0);

	if (sign < 0) {
		/*add negative sign back if num was originally negative*/
		s[i++] = '-';
	}
	/* add a null terminating character at the end to make the string valid*/
	s[i] = '\0';
	reverse(s);
}

/*Testing the function
int main() {
	char str[30];
	int n = 23;
	_itoa(n, str);
	write(1, str, strlen(str)); // prints '23'
}*/

