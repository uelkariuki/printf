#include "main.h"

/**
 * Functions that handle conversion specifiers
*/


/**
 * print_int - prints an integer to the standard output
 * @args: The argument list containing the integer to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_int(va_list args) {
	/* handles conversion specifier d and i*/
	int num;
	char *res;

	num = va_arg(args, int);
	res = malloc(20);
	if (res == NULL) {
		return -1;
		}
	_itoa(num, res);
	return write(1, res, _strlen(res));
	free(res);
}

/**
 * print_char - prints a character to the standard output
 * @args: The argument list containing the character to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_char(va_list args) {
	char c;

	c = (char) va_arg(args, int);
	return write(1, &c, 1);
	}

/**
 * print_str - prints a string to the standard output
 * @args: The argument list containing the string to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_str(va_list args) {
	char *str;

	str = va_arg(args, char *);
	if (str == NULL) str = "(null)";
	return write(1, str, _strlen(str));
	}

/**
 * print_binary - converts unsigned integer to binary and prints it
 * @args: The argument list containing the unsigned integer to convert
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_binary(va_list args) {
	unsigned int num;
	char *res;
	size_t length;
	ssize_t bytes_written;

	num = va_arg(args, unsigned int);
	res = malloc(33);
	if (res == NULL) {
		return -1;
	}
	to_binary(num, res);
	length = _strlen(res);
	bytes_written = write(1, res, length);
	/* In case of write error*/
	if (bytes_written == -1) {
		free(res);
		return -1;
	}
	free(res);
	return bytes_written;
	}
/**
 * print_unsigned - prints unsigned integers to the standard output
 * @args: The argument list containing the unsigned integers to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_unsigned(va_list args) {
	unsigned int num;
	char *res;
	size_t length;
	ssize_t bytes_written;

	num = va_arg(args, unsigned int);
	res = malloc(12);
	if (!res) return -1;
	_uitoa(num, res);
	length = _strlen(res);
	bytes_written = write(1, res, length);
	/* In case of write error*/
	if (bytes_written == -1) {
		free(res);
		return -1;
		}
	free(res);
	return bytes_written;
	}
