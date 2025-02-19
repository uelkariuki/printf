#include "main.h"

/**
 * _printf - A function that produces output based on format
 * @format: The character string
 *
 * Returns: The number of characters printed (excluding the null byte used to end output to strings)
*/

int _printf(const char *format, ...) {
	va_list args;

	int i, j, found, buf_index = 0;
	char c;
	buffer_t buf = {{0}, 0, 0};

	va_start(args, format);
	int count = 0;
	/* get access to the lookup table */
	specifier_t *specifiers = get_specifiers();
	/* loop through the string and deal with subsequent cases */
	for (i = 0; format[i] != '\0'; i++) {
		/* if '%' is found in string*/
		if (format[i] == '%') {
			/* go to next character after % */
			i++;
			if (format[i] == '%') {
				buf.buffer[buf.index++] = '%';
				count++;
				continue;
			}
			j = 0; found = 0;
			/* loop through the specifiers */
			while (specifiers[j].spec) {
				/* if the specific specifier is found */
				if (format[i] == specifiers[j].spec){
					/* call the function and increment the count*/
					count += specifiers[j].func(args, &buf);
					found = 1;
					break;
					}
					j++;
			}
			/* if specifier not in specifier array print as is*/
			if (!found) {
				buf.buffer[buf.index++] = '%';
				buf.buffer[buf.index++] = format[i];
				/* increase count by 2 as characters have been printed*/
				count+=2;
			}
		/* if there was no '%' at the start print the string as is */
		} else {
			buf.buffer[buf.index++] = format[i];
			count++;
		}
		/*If buffer is full flush it (write it to stdout) and reset the buffer index */
		if (buf.index >= BUFFER_SIZE) {
			write(1, buf.buffer, buf.index);
			buf.index = 0;
		}
	}
	/*if there is still anything left in the buffer write it to stdout
	for example if string length was less than 1024 bytes, this ensures
	nothing is left in the buffer*/
	if (buf.index > 0) {
		write(1, buf.buffer, buf.index);
		buf.index = 0;
	}
	va_end(args);
	return count;

}
