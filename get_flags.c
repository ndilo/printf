#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @k: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *k)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int l, curr_j;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_j = *k + 1; format[curr_j] != '\0'; curr_j++)
	{
		for (l = 0; FLAGS_CH[l] != '\0'; l++)
			if (format[curr_j] == FLAGS_CH[l])
			{
				flags |= FLAGS_ARR[l];
				break;
			}

		if (FLAGS_CH[l] == 0)
			break;
	}

	*k = curr_j - 1;

	return (flags);
}


