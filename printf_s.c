#include "main.h"

/**
 * printf_string - print string
 * @args: inputs parameter
 *
 * Return: the string's length.
 */

int printf_string(va_list args)
{
	char *str;
	int j;
	int length;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);
		for (j = 0; j < length; j++)
			_putchar(str[j]);
		return (length);
	}
	else
	{
		length = _strlen(str);

		j = 0;

		while (j < length)
		{
			_putchar(str[j]);
			j++;
		}
		return (length);
	}
}
