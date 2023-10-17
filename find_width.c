#include "main.h"

/**
 * find_width - find the width for printing
 * @format: Format arguments.
 * @i: arguments to be printed.
 * @args: list of arguments
 * Return: width
 */
int find_width(const char *format, int *i, va_list args)
{
	int count;
	int width = 0;

	for (count = *i + 1; format[count] != '\0'; count++)
	{
		if (is_digit(format[count]))
		{
			width *= 10;
			width += format[count] - '0';
		}
		else if (format[count] == '*')
		{
			count;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = count - 1;

	return (width);
}
