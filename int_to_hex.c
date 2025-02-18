#include "main.h"

/**
 * to_hex - function that converts an unsigned integer to its hexadecimal
 * string representation
 * @n: the unsigned integer to be converted
 * @s: the string to store the converted hexadecimal value
 *
 *
*/

void to_hex(unsigned int n, char *s) {
	unsigned int rem, i = 0;

	if (n == 0) {
		s[i++] = '0';
	} else {
		while(n != 0) {
			rem = n % 16;
			if (rem < 10) {
				s[i++] = rem + '0';
				} else {
					s[i++] = rem + 'a' - 10;
					}
					n /= 16;
		}
	}
	s[i] = '\0';
	reverse(s);
}

/*
int main(void) {
	unsigned int num = 160;
	char str[12];
	to_hex(num, str);
	printf("The hex val of %u is %s", num, str);
}*/
