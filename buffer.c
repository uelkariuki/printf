#include "main.h"

/**
 *buffer - Function to save the character in a buffer
 *@c: Character
 *
 *Return: 1
 */
int buffer(char c)
{
	static char buffering[1024];
	static int a;

	if (c == -1 || a == 1024)
	{
		write(1, buffering, a);
		a = 0;
	}

	if (c != -1)
		buffering[a++] = c;

	return (1);
}
