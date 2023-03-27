#include "main.h"


/**
 * my_printf-A printf-style function that supports the field width flag '-' for non-custom conversion specifiers.
 * @param format The format string.
 * @param ... The arguments to be printed.
 * @return The number of characters printed.
 */
int width_specifier(const char* format, ...) {
  va_list args; 
  int count = 0;
  int field_width;

  va_start(args, format);
  while (*format) {
    if (*format == '%') {/* if current character is conversion specifier*/
      format++; /*advance the format string pointer to the conversion specifier*/
      field_width = 0;
      if (*format == '-') { /*check if the field width flag is set*/
        format++; /*advance the format string pointer to the field width*/
        while (*format >= '0' && *format <= '9') { /* loop over the digits in the field width*/
          field_width = 10 * field_width + (*format - '0'); /* parse the field width as an integer*/
          format++;
        }
      }
      /* output the argument with the specified field width*/
      switch (*format) { 
        case 'c':
          count += printf("%c", va_arg(args, int)); 
          break;
        case 'd':
          if (field_width > 0) {
            count += printf("%*d", -field_width, va_arg(args, int)); /* output the integer argument with left alignment and update the character count*/
          } else {
            count += printf("%d", va_arg(args, int)); /*output the integer argument with default alignment and update the character count*/
          }
          break;
        case 's':
          if (field_width > 0) {
            count += printf("%-*s", field_width, va_arg(args, char*)); /*output the string argument with left alignment and update the character count*/
          } else {
            count += printf("%s", va_arg(args, char*)); /* output the string argument with default alignment and update the character count*/
          }
          break;
        default: /* unsupported conversion specifier*/
          count += printf("?"); /*output a question mark and update the character count*/
          break;
      }
      format++; /* advance the format string pointer past the conversion specifier*/
    } else { /* normal character*/
      count += printf("%c", *format); /*output the character and update the character count*/
      format++;
    }
  }
  va_end(args);
  return (count);
}

