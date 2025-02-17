#include "main.h"


/**
 * _strlen - Function that returns the length of a string s
 * @s: the string whose length is to be calculated
 *
 * Return: The length of the string
*/

int _strlen(char *s) {
	int n;

	for (n = 0; *s != '\0'; s++) {
		n++;
	}
	return n;
}
/** Testing the function
int main() {
	char *s = "Hello";
	int n = _strlen(s);
	printf("The length of the string is %d\n", n);
	return 0;
}*/

