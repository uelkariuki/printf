#include "main.h"

/**
 * More functions that handle conversion specifiers
*/


/**
 * print_octal - prints unsigned octal to the standard output
 * @args: The argument list containing the unsigned integers to be converted
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_octal(va_list args) {
	unsigned int n;
	char *str;
	ssize_t bytes_written;

	n = va_arg(args, unsigned int);
	str = malloc(33);
	if (!str) return -1;
	to_octal(n, str);
	bytes_written = write(1, str, _strlen(str));
	if (bytes_written == -1) {
		free(str);
		return -1;
	}
	free(str);
	return bytes_written;
}


/**
 * print_Hex - prints unsigned Hexadecimal to the standard output
 * @args: The argument list containing the unsigned integers to be converted
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_Hex(va_list args) {
	unsigned int n;
	char *str;
	ssize_t bytes_written;

	n = va_arg(args, unsigned int);
	str = malloc(12);
	if (!str) return -1;
	to_Hex(n, str);
	bytes_written = write(1, str, _strlen(str));
	if (!bytes_written) {
		free(str);
		return -1;
	}
	free(str);
	return bytes_written;
}

/**
 * print_hex - prints unsigned hexadecimal to the standard output
 * @args: The argument list containing the unsigned integers to be converted
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_hex(va_list args) {
	unsigned int n;
	char *str;
	ssize_t bytes_written;

	n = va_arg(args, unsigned int);
	str = malloc(12);
	if (!str) return -1;
	to_hex(n, str);
	bytes_written = write(1, str, _strlen(str));
	if (!bytes_written) {
		free(str);
		return -1;
	}
	free(str);
	return bytes_written;
}
