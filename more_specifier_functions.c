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
int print_octal(va_list args, buffer_t *buf) {
	unsigned int n;
	char str[BUFFER_SIZE];
	int i = 0;

	n = va_arg(args, unsigned int);
	to_octal(n, str);

	while(str[i]) {
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
 * print_Hex - prints unsigned Hexadecimal to the standard output
 * @args: The argument list containing the unsigned integers to be converted
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_Hex(va_list args, buffer_t *buf) {
	unsigned int n;
	char str[BUFFER_SIZE];
	int i = 0;

	n = va_arg(args, unsigned int);
	to_Hex(n, str);

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
 * print_hex - prints unsigned hexadecimal to the standard output
 * @args: The argument list containing the unsigned integers to be converted
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_hex(va_list args, buffer_t *buf) {
	unsigned int n;
	char str[BUFFER_SIZE];
	int i = 0;

	n = va_arg(args, unsigned int);
	to_hex(n, str);
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
 * print_String - prints converted string to the standard output
 * @args: The argument list containing the string to be converted
 *
 * Return: The number of characters printed on success, -1 on failure
*/
int print_String(va_list args, buffer_t *buf) {
	int step, i = 0;
	char *str;

	str = va_arg(args, char *);
	if (!str) str = "(null)";
	while (str[i]) {
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127) {
			step = str_to_ASCII(&str[i], buf);
			i += step;
		} else {
			buf->buffer[buf->index++] = str[i];
			buf->count++;

			if (buf->index == 1024) {
				write(1, buf->buffer, buf->index);
				buf->index = 0;
			}
			i++;
		}


	}
	return i;

}
