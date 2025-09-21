#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * array_iterator - prototype for function that executes
 *                  a function on each element of an array
 * @array: pointer to the array of integers
 * @size: size of the array
 * @action: pointer to the function used on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int));

#endif /* FUNCTION_POINTERS_H */
