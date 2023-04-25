#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @j: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *j, va_list list)
{
	int curr_k = *j + 1;
	int precision = -1;

	if (format[curr_k] != '.')
		return (precision);

	precision = 0;

	for (curr_k += 1; format[curr_k] != '\0'; curr_k++)
	{
		if (digit(format[curr_k]))
		{
			precision *= 10;
			precision += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*j = curr_k - 1;

	return (precision);
}


