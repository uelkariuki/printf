#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);

int handle_printing_funct(const char *fmt, int *ind, va_list list,
		char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int char_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int string_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int percent_specifier(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */

int unsigned_int_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int binary_func(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int int_function(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);
int octal_funct(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int hexadmal(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);
int hexa_up(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int hex_funct(va_list arguments, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int non_printable(va_list arguments, char buffer[],
		int flags, int width, int precision, int size);

int pointer_func(va_list arguments, char buffer[], int flags, int width,
		int precision, int size);

/* Funciotns to handle other specifiers */
int flags_funct(const char *format, int *x);
int width_func(const char *format, int *w, va_list list);
int precision_funct(const char *format, int *i, va_list list);
int size_funct(const char *format, int *i);

/*Function to print string in reverse*/
int reverse_string(va_list arguments, char buffer[],
	int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int rot13(va_list arguments, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handles_write_charac(char c, char buffer[],
		int flags, int width, int precision, int size);
int handle_write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision, int size);
int write_num_buff(int ind, char bff[], int flags, int width,
		int precision, int length, char padd, char extra_c);

int write_pointer_func(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);


int write_unsgnd_func(int is_negative, int ind,
		char buffer[], int flags, int width, int precision, int size);

int char_is_printable(char c);
int hexa_code_appending(char _ascii_code, char buffer[], int x);
int char_is_digit(char);

long int cast_number_to_size(long int numbr, int size_n);
long int cast_size_unsgnd(unsigned long int numbr, int size_u);
#endif /* MAIN_H */
