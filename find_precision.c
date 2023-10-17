#include "main.h"

/**
 * find_precision - gets the precision for printing
 * @format: Format arguments
 * @i: List of arguments printed
 * @args: list of arguments
 *
 * Return: Precision
 */
int find_precision(const char *format, int *i, va_list args)
{
	int count = *i + 1;
	int precision = -1;

	if (format[count] != '.')
		return (precision);

	precision = 0;

	for (count += 1; format[count] != '\0'; count++)
	{
		if (is_digit(format[count]))
		{
			precision *= 10;
			precision += format[count] - '0';
		}
		else if (format[count] == '*')
		{
			count++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = count - 1;

	return (precision);
}
