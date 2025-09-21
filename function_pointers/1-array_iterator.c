#include "function_pointers.h"
#include <stddef.h>

/**
 * array_iterator - executes a function given as a parameter
 *                  on each element of an array
 * @array: pointer to the array of integers
 * @size: size of the array
 * @action: pointer to the function to be used
 *
 * Description: This function iterates through an array and applies
 *              the function pointed to by action on each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
