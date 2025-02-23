#include "main.h"
#include <stdio.h>

/**
 * str_to_ASCII- function that converts a string to its ASCII representation
 * @str: The string to be evaluated and converted
 * @buf: buffer used to store the converted result
 *
 * Return: The number of characters added to the buffer
 *
*/

int str_to_ASCII(char *str, buffer_t *buf) {
	int i = 0;
	char res[3];

	while(str[i]) {
		/*(0 < ASCII value < 32 or >= 127) */

		if ((str[i] > 0 && str[i] < 32) || (str[i] >= 127)) {
			/**
			 * If char is found add \x to it after which convert the non printable
			 * character to its Hex value and if a case like \n is found, its ASCII value
			 * in Hex is 'A', we need 2 characters always, so check the next value in res
			 * array if it is the null terminating character. If it is prepend a '0'
			 * before the first value else add the chars as they are to the buffer
			 */
			buf->buffer[buf->index++] = '\\';
			buf->buffer[buf->index++] = 'x';
			to_Hex(str[i], res);


			if (res[1] == '\0') {
				buf->buffer[buf->index++] = '0';
				buf->buffer[buf->index++] = res[0];
			} else {
				buf->buffer[buf->index++] = res[0];
				buf->buffer[buf->index++] = res[1];
			}

		} else{
			/* if no non printable character is encountered */
			buf->buffer[buf->index++] = str[i];
			buf->count++;
		}
		buf->count++;

		if (buf->index == 1024) {
			write(1, buf->buffer, buf->index);
			buf->index = 0;
		}

		i++;
	}
	return i;
}
/*
int main(void) {
	char *s = "Best\nSchool";
	buffer_t buf;
	buf.index = 0;
	buf.count = 0;

	str_to_ASCII(s, &buf);

	write(1, buf.buffer, buf.index);


}*/
