#include "main.h"

// function to print the reversed string of a given input string
// input: s - a null-terminated string
void print_reversed_string(const char *s) 
{
    int len = strlen(s);
    char reversed_string[len+1];  // create a new character array with the same length as s
    for (int i = len-1; i >= 0; i--) {
        reversed_string[len-i-1] = s[i];  // copy the characters of s to reversed_string in reverse order
    }
    reversed_string[len] = '\0';  // add a null character at the end of reversed_string to terminate the string
    printf("%s", reversed_string);  // print the reversed string using the %s specifier
}
