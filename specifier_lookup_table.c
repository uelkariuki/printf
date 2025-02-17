#include "main.h"

specifier_t specifiers[] = {
	{'d', print_int},
	{'s', print_str},
	{'c', print_char},
	{'b', print_binary},
	{'i', print_int},
	{'u', print_unsigned},
	{'o', print_octal},
	{'X', print_Hex},
	{'x', print_hex},
	{'\0', NULL}
	};

/* Function that returns the specifiers array */
/* It returns a pointer to the first element of the array */
specifier_t *get_specifiers(void) {
	return specifiers;
}
