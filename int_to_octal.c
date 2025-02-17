#include "main.h"

/**
 * to_octal - converts unsigned integers to an octal string representation
 * @k: the unsigned integer to convert
 * @s: the string used to store the converted octal value
 *
 * Description: Converts a unsigned integer to an octal number and stores it as a string
*  in the given buffer
 *
 * Return: This function does not return a value
*/

void to_octal(unsigned int k, char *s) {
	unsigned int i = 0;

	if (k == 0) {
		s[i++] = '0';
	}
	else {
		while (k > 0) {
			s[i++] = (k % 8) + '0';
			k /= 8;
		}
	}
	s[i] = '\0';
	reverse(s);
}
/*
int main(void) {
	unsigned int num = 2147484671;
	char str[20];

	to_octal(num, str);
	printf("The octal of %u is %s",num, str); /*The octal of 2147484671 is 20000001777
}*/
