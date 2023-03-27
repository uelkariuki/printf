#include "main.h"

/**
 *print_pointer_address- function to print the memory address of a pointer 
 *                       variable using the %p conversion specifier.
 *@ptr:Pointer to the variable to print the address of.
 */
void print_pointer_address(void* ptr) 
{
	printf("Address of pointer = %p\n", ptr);
}
