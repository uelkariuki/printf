#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 *my_print- A printf-style function that supports the - flag for left justification
 * of non-custom conversion specifiers.
 *
 * @format The format string.
 *Return: The number of characters printed.
 */
int my_printf(const char* format, ...) {
  va_list args;
  char *arg;
  int left_justify;
  int iarg;
  int count = 0;

  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      /*Check for the - flag*/
      left_justify = 0;
      if (*format == '-') {
        left_justify = 1;
        format++;
      }
      /*Parse the conversion specifier*/
      if (*format == 'd') {
        /*Handle the %d conversion specifier*/
	      iarg = va_arg(args, int);
        if (left_justify) {
          count += printf("%d ", iarg);
        } else {
          count += printf(" %d", iarg);
        }
      } else if (*format == 's') {
        /*Handle the %s conversion specifier*/
	      arg = va_arg(args, char*);
        if (left_justify) {
          count += printf("%s ", arg);
        } else {
          count += printf(" %s", arg);
        }
      } else {
        /* Unsupported conversion specifier, print a question mark*/
        count += printf("?");
      }
      format++;
    } else {
      /*Normal character, just output it*;*/
      count += printf("%c", *format);
      format++;
    }
  }
  va_end(args);
  return count;
}

