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
int print_int(va_list args, buffer_t *buf) {
	/* handles conversion specifier d and i*/
	int num, i = 0;
	char res[BUFFER_SIZE];
	ssize_t bytes_written;

	num = va_arg(args, int);
	_itoa(num, res);

	while (res[i]) {
		buf->buffer[buf->index++] = res[i++];
		buf->count++;

		/* if buffer is full flush it and reset the buffer index*/
		/* This is to prevent buffer overflow*/
		if (buf->index == 1024) {
			write(1, buf->buffer, buf->index);
			buf->index = 0;
		}
	}
	return i;
}

/**
 * print_char - prints a character to the standard output
 * @args: The argument list containing the character to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_char(va_list args, buffer_t *buf) {
	char c;

	c = (char) va_arg(args, int);

	buf->buffer[buf->index++] = c;
	buf->count++;

	if (buf->index == 1024) {
		write(1, buf->buffer, buf->index);
		buf->index = 0;
	}

	return 1;
}

/**
 * print_str - prints a string to the standard output
 * @args: The argument list containing the string to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_str(va_list args, buffer_t *buf) {
	char *str;
	int i = 0;

	str = va_arg(args, char *);
	if (str == NULL) str = "(null)";

	while (str[i]) {
		buf->buffer[buf->index++] = str[i++];
		buf->count++;

		if (buf->index == 1024) {
			write(1, buf->buffer, buf->index);
			buf->index = 0;
			}
	}

	return i;
	}

/**
 * print_binary - converts unsigned integer to binary and prints it
 * @args: The argument list containing the unsigned integer to convert
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_binary(va_list args, buffer_t *buf) {
	unsigned int num;
	char res[33];
	int i = 0;

	num = va_arg(args, unsigned int);

	to_binary(num, res);

	while (res[i])
	{
		buf->buffer[buf->index++] = res[i++];
		buf->count++;

		if (buf->index == 1024) {
			write(1, buf->buffer, buf->index);
			buf->index = 0;
		}

	}
	return i;

}
/**
 * print_unsigned - prints unsigned integers to the standard output
 * @args: The argument list containing the unsigned integers to print
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_unsigned(va_list args, buffer_t *buf) {
	unsigned int num;
	char res[BUFFER_SIZE];
	int i = 0;

	num = va_arg(args, unsigned int);

	_uitoa(num, res);

	while (res[i]) {
		buf->buffer[buf->index++] = res[i++];
		buf->count++;

		if (buf->index == 1024) {
			write(1, buf->buffer, buf->index);
			buf->index = 0;
		}
	}
	return i;
}
