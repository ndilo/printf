#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @b: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *b)
{
	int curr_j = *b + 1;
	int size = 0;

	if (format[curr_j] == 'l')
		size = S_LONG;
	else if (format[curr_j] == 'h')
		size = S_SHORT;

	if (size == 0)
		*b = curr_j - 1;
	else
		*b = curr_j;

	return (size);
}
