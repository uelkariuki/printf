#include "main.h"

int reverse_string(const char* format, ...) 
{
  va_list args;
  int len, i;
  char *arg;
  int count = 0;

  va_start(args, format);
  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == 'r') {
	      arg = va_arg(args, char*);
	      len = strlen(arg);
        for (i = len - 1; i >= 0; i--) {
          count += printf("%c", arg[i]);
        }
      } else {
        count += printf("?");
      }
      format++;
    } else {
      count += printf("%c", *format);
      format++;
    }
  }
  va_end(args);
  return count;
}

