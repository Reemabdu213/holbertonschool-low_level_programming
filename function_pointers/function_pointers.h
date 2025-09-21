#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/**
 * print_name - prints a name using a function pointer
 * @name: the name to be printed
 * @f: pointer to a function that prints the name
 */
void print_name(char *name, void (*f)(char *));

/* (optional for later tasks) */
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif /* FUNCTION_POINTERS_H */
