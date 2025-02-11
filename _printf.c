#include "main.h"

/**
 * A function that produces output based on format
 * Returns: The number of characters printed (excluding the null byte used to end output to strings)
 *
*/

int _printf(const char *format, ...) {
	va_list args;

	int i;
	char c;
	char *str;

	va_start(args, format);
	int count = 0;
	/* loop through the string and deal with subsequent cases */
	for (i = 0; format[i] != '\0'; i++) {
		if (format[i] != '%') {
			write(1, &format[i], 1);
			count++;
		}
		/* conversion specifier c */
		else if (format[i] == '%' && format[i + 1] == 'c') {
			c = (char) va_arg(args, int);
			write(1, &c, 1);
			i++;
			count++;
		}
		/*conversion specifier s */
		else if (format[i] == '%' && format[i + 1] == 's') {
			str = va_arg(args, char *);
			if (str == NULL) str = "(null)";
			write(1, str, _strlen(str));
			i++;
			count++;
		}
		/* conversion specifier % */
		else if (format[i] == '%' && format[i + 1] == '%') {
			char percent = '%';
			write(1,&percent, 1);
			i++;
			count++;

		}
		/*conversion specifier d and i*/
		else if ((format[i] == '%' && format[i + 1] == 'd') ||
		        (format[i] == '%' && format[i + 1] == 'i')) {
			int num = va_arg(args, int);
			char *res = malloc(20);
			if (res == NULL) {
				return -1;
			}
			_itoa(num, res);
			write(1, res, _strlen(res));
			count += _strlen(res);
			i++;
			free(res);
		}
		/* custom conversion specifier b */
		else if  ((format[i] == '%' && format[i + 1] == 'b')) {
			int num = va_arg(args, int);
			int binaryRes = toBinary(num);
			char *res = malloc(12);
			if (res == NULL) {
				return -1;
			}
			_itoa(binaryRes, res);
			write(1, res, _strlen(res));
			count += _strlen(res);
			i++;
			free(res);

		}

	}
	va_end(args);
	return count;

}
