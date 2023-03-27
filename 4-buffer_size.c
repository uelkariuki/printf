#include "main.h"

#define BUFFER_SIZE 1024

/**
  *my_printf-This function takes a format string and variable number of arguments as input,
  *formats the string according to the format specifier, and writes the output to stdout.
  *@format: The format string containing conversion specifiers
  *Return: The total number of characters written to stdout
  */

int my_printf(const char* format, ...) 
{
	int chars_written = 0; /* initialize the number of characters written to zero*/
	char buffer[BUFFER_SIZE]; /*create a buffer of 1024 chars*/
	va_list args; 
	int i;
    /*use vsnprintf to format the string and store it in the buffer*/
	int len = vsnprintf(buffer, BUFFER_SIZE, format, args);

	va_start(args, format); /*initialize the argument list with the format string*/

    /*check if the formatted string fits in the buffer*/
	if (len < BUFFER_SIZE) 
	{
		/*if it fits, write the formatted string to stdout using a single call to write*/
		chars_written = write(STDOUT_FILENO, buffer, len);
    
	} else 
	{
        /*if it doesn't fit, write the buffer in chunks of size BUFFER_SIZE*/
        /*until the entire formatted string is written to stdout*/
		for (i = 0; i < len; i += BUFFER_SIZE) 
		{
			chars_written += write(STDOUT_FILENO, buffer + i, BUFFER_SIZE);
		}
	}
	va_end(args); /*free the argument list*/
	return (chars_written); /*return the total number of characters written to stdout*/
}

