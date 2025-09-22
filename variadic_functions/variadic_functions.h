#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of integers to sum
 *
 * Return: sum of numbers, or 0 if n == 0
 */
int sum_them_all(const unsigned int n, ...);

/**
 * print_numbers - prints numbers, followed by a new line
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_all(const char * const format, ...);
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_all(const char * const format, ...);

/**
 * print_strings - prints strings, followed by a new line
void print_all(const char * const format, ...);
void print_all(const char * const format, ...);
 * @separator: string to be printed between strings
 * @n: number of strings passed to the function
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
void print_all(const char * const format, ...);

/**
 * print_all - prints anything (numbers, chars, strings, floats)
 * @format: list of types of arguments passed to the function
 *
 * Return: void
 */
void print_all(const char * const format, ...);

#endif /* VARIADIC_FUNCTIONS_H */
