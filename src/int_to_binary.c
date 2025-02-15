#include "main.h"
#include <stdio.h>

/**
 * Function that converts an unsigned integer to binary
*/

void toBinary(unsigned int k, char *s) {
	unsigned int i = 0;

	if (k == 0) {
		s[i++] = '0';
	}
	else {
		while (k > 0) {
			s[i++] = (k % 2) + '0';
			k /= 2;

		}
	}
	s[i] = '\0';
	reverse(s);
}
/* Testing the function
int main() {
	unsigned int n = 1000;
	char str[33];
	toBinary(n, str);
	printf("The binary value of %u is %s\n", n, str);
}*/
