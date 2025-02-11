#ifndef MAIN_H /* if MAIN_H is not defined*/
#define MAIN_H /*define MAIN_H */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int _printf(const char *format, ...);
void reverse(char s[]);
void _itoa(int num, char s[]);
int _strlen(char *s);
int toBinary(int k);

#endif

