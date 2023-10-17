#include "main.h"

/**
 * find_flags - Calculates the flags
 * @format: Format arguments
 * @i: parameter
 * Return: Flags
 */
int find_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int a, count;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (count = *i + 1; format[count] != '\0'; count++)
	{
		for (a = 0; FLAGS_CHAR[a] != '\0'; a++)
			if (format[count] == FLAGS_CHAR[a])
			{
				flags |= FLAGS_ARRAY[a];
				break;
			}

		if (FLAGS_CHAR[a] == 0)
			break;
	}

	*i = count - 1;

	return (flags);
}
