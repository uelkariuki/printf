#ifndef MAIN_H /* if MAIN_H is not defined*/
#define MAIN_H /*define MAIN_H */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 1024

typedef struct buffer_s {
	char buffer[1024]; /* buffer used to store the characters */
	int index; /* keeps track of where to write text */
	int count; /* keeps count of the number of characters written */
} buffer_t;

typedef struct specifier {
	char spec;
	int (*func)(va_list, buffer_t *);
} specifier_t;

int print_int(va_list args, buffer_t *buf);
int print_str(va_list args, buffer_t *buf);
int print_binary(va_list args, buffer_t *buf);
int print_char(va_list args, buffer_t *buf);
int print_unsigned(va_list args, buffer_t *buf);
int print_octal(va_list args, buffer_t *buf);
int print_Hex(va_list args, buffer_t *buf);
int print_hex(va_list args, buffer_t *buf);
int print_String(va_list args, buffer_t *buf);

specifier_t *get_specifiers(void);

int _printf(const char *format, ...);
void reverse(char s[]);
void _itoa(int num, char s[]);
int _strlen(char *s);
void to_binary(unsigned int k, char *s);
void _uitoa(unsigned int num, char s[]);
void to_octal(unsigned int k, char *s);
void to_Hex(unsigned int n, char *s);
void to_hex(unsigned int n, char *s);
int str_to_ASCII(char *str, buffer_t *buf);

#endif

