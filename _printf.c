#include "main.h"

/**
 * A function that produces output based on format
 * Returns: The number of characters printed (excluding the null byte used to end output to strings)
 *
*/

int _printf(const char *format, ...) {
	va_list args;

	int i, j, found;
	char c;
	char *str;

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
				write(1, "%", 1);
				count++;
				continue;
			}
			j = 0; found = 0;
			/* loop through the specifiers */
			while (specifiers[j].spec) {
				/* if the specific specifier is found */
				if (format[i] == specifiers[j].spec){
					/* call the function and increment the count*/
					count += specifiers[j].func(args);
					found = 1;
					break;
					}
					j++;
			}
			/* if specifier not in specifier array print as is*/
			if (!found) {
				write(1,"%", 1);
				write(1, &format[i], 1);
				/* increase count by 2 as characters have been printed*/
				count++;
			}
		/* if there was no '%' at the start print the string as is */
		} else {
			write(1, &format[i], 1);
			count++;

		}

	}
	va_end(args);
	return count;

}
