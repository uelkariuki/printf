#include "main.h"

// function to ROT13-encode a given input string and print the result
// input: s - a null-terminated string
void print_rot13_string(const char *s) {
    int len = strlen(s);
    char rot13_string[len+1];  // create a new character array with the same length as s
    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c >= 'a' && c <= 'z') {  // if c is a lowercase letter
            c = 'a' + ((c - 'a' + 13) % 26);  // apply ROT13 encoding
        } else if (c >= 'A' && c <= 'Z') {  // if c is an uppercase letter
            c = 'A' + ((c - 'A' + 13) % 26);  // apply ROT13 encoding
        }
        rot13_string[i] = c;  // copy the encoded character to the corresponding position in rot13_string
    }
    rot13_string[len] = '\0';  // add a null character at the end of rot13_string to terminate the string
    printf("%s", rot13_string);  // print the ROT13-encoded string using the %s specifier
}
