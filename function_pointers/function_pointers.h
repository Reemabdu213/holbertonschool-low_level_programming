#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * print_name - prints a name using a function pointer
 * @name: the name to be printed
 * @f: pointer to a function that prints the name
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */
