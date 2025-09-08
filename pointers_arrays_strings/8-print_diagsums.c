#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints sums of the two diagonals
 *                  of a square matrix of integers
 * @a: pointer to first element of matrix (as 1D array)
 * @size: matrix size (rows = cols)
 */
void print_diagsums(int *a, int size)
{
	int i, sum1 = 0, sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
	}
	printf("%d, %d\n", sum1, sum2);
}
