#include "main.h"

/**
 * Function that reverses a string in place
*/

void reverse(char s[]) {
	int c, i, j;

	/* i starts from the beginning and j starts from the end*/
	/*and loop stops when they meet at the middle i == j*/
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
