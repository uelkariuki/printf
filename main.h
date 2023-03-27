#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


int _printf(const char *format, ...);
void print_with_custom_specifiers(const char *format, ...);
void print_number(unsigned int num, char spec);
int my_printf(const char* format, ...);
void print_string(char* str);
void print_pointer_address(void* ptr);
void print_float_with_flags(float val, int plus, int space, int hash, int precision);
void print_integer_with_length_modifier(int val, char length, char specifier);
int width_specifier(const char* format, ...);
int find_precision(const char *format, int *i, va_list list);
char *convert(unsigned long int num, int base, int lowercase);
int my_printf(const char* format, ...);
int reverse_string(const char* format, ...);
int rot_13(const char* format, ...);

#endif /* main.h */
