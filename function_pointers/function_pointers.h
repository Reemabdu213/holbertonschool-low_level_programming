i#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

#include <stddef.h>

/**
 * array_iterator - executes a function on each element of an array
 * @array: pointer to the array of integers
 * @size: size of the array
 * @action: pointer to the function used on each element
 */
void array_iterator(int *array, size_t size, void (*action)(int));

/**
 * int_index - searches for an integer in an array
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 * @cmp: pointer to the comparison function
 *
 * Return: index of the first element for which cmp does not return 0,
 *         -1 if no element matches or if size <= 0
 */
int int_index(int *array, int size, int (*cmp)(int));

#endif /* FUNCTION_POINTERS_H */
