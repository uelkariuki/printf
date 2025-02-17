#ifndef MAIN_H /* if MAIN_H is not defined*/
#define MAIN_H /*define MAIN_H */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct specifier {
	char spec;
	int (*func)(va_list);
} specifier_t;

int print_int(va_list args);
int print_str(va_list args);
int print_binary(va_list args);
int print_char(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);


specifier_t *get_specifiers(void);

int _printf(const char *format, ...);
void reverse(char s[]);
void _itoa(int num, char s[]);
int _strlen(char *s);
void to_binary(unsigned int k, char *s);
void _uitoa(unsigned int num, char s[]);
void to_octal(unsigned int k, char *s);

#endif

