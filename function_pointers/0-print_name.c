#include "function_pointers.h"

/**
 * print_name - prints a name using the function passed as parameter
 * @name: the name to print
 * @f: pointer to a function that takes a char* and returns void
 *
 * Return: Nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}
