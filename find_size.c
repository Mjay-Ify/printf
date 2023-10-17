#include "main.h"

/**
 * find_size - get the size to cast the argument
 * @format: Format arguments
 * @i: List of arguments
 * Return: Precision
 */
int find_size(const char *format, int *i)
{
	int count = *i + 1;
	int size = 0;

	if (format[count] == 'l')
		size = S_LONG;
	else if (format[count] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = count - 1;
	else
		*i = count;

	return (size);
}
