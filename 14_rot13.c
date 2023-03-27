#include "main.h"

/**
 * my_printf-A printf-style function that supports the %R custom conversion specifier,
 * which prints the rot13'ed string.
 *
 * @format The format string.
 * @param ... The arguments to be printed.
 * Return:The number of characters printed.
 */
int rot_13(const char* format, ...) {
  va_list args; /* define the va_list object to hold the variable arguments*/
  char *arg;
  int i, len;
  char c;
  int count = 0;

  va_start(args, format);  
  while (*format) { /* loop over the characters in the format string*/
    if (*format == '%') { 
      format++; /*advance the format string pointer to the conversion specifier*/
      /*Check for the R conversion specifier*/
      if (*format == 'R') {
        arg = va_arg(args, char*);
        len = strlen(arg); 
        for (i = 0; i < len; i++) { 
          c = arg[i]; /* get the current character*/
          if (c >= 'a' && c <= 'z') { /*check if the character is lowercase*/
            c = ((c - 'a') + 13) % 26 + 'a'; /* apply the rot13 transformation for lowercase letters*/
          } else if (c >= 'A' && c <= 'Z') { /* check if the character is uppercase*/
            c = ((c - 'A') + 13) % 26 + 'A'; /* apply the rot13 transformation for uppercase letters*/
          }
          count += printf("%c", c); /* output the transformed character and update the character count*/
        }
      } else { /*unsupported conversion specifier*/
        count += printf("?"); /*output a question mark and update the character count*/
      }
      format++; /*advance the format string pointer past the conversion specifier*/
    } else { /* normal character*/
      count += printf("%c", *format); /* output the character and update the character count*/
      format++; /* advance the format string pointer*/
    }
  }
  va_end(args); 
  return (count); 
}

