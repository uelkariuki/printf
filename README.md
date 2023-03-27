# 0x11. C - printf
##Group Tasks

0. Write a function that produces output according to a format.
9. Handle the field width for non-custom conversion specifiers.
10. Handle the precision for non-custom conversion specifiers.
11. Handle the 0 flag character for non-custom conversion specifiers.
12. Handle the - flag character for non-custom conversion specifiers.
13. Handle the following custom conversion specifier:

r : prints the reversed string
14. Handle the following custom conversion specifier:

R: prints the rot13'ed string


for reference of prototypes, the delete!
's' , int conversion_specifier(const char *format, ...)
'd' int conversion_specifier(const char *format, ...)
'b' void print_with_custom_specifiers(const char *format, ...)
'o' void print_number(unsigned int num, char spec)
'X' void print_integer_with_length_modifier(int val, char length, char specifier)
'r'  int reverse_string(const char* format, ...)
