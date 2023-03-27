#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>


int _printf(const char *format, ...);
void print_with_custom_specifiers(const char *format, ...);
void print_number(unsigned int num, char spec);
int my_printf(const char* format, ...);
void print_string(char* str);
void print_pointer_address(void* ptr);
void print_float_with_flags(float val, int plus, int space, int hash, int precision);
void print_integer_with_length_modifier(int val, char length, char specifier);
#endif /* main.h */
