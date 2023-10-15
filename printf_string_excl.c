#include "main.h"
/**
 * printf_string_excl - prints just string.
 * @value: inputs argument.
 *
 * Return: The string's length.
 */

int printf_string_excl(va_list value)
{
	char *s;
	int j = 0;
	int length = 0;
	int val;

	s = va_arg(value, char *);
	if (s == NULL)
		s = "(null)";

	j = 0;

	while (s[j] != '\0')
	{
		if (s[j] < 32 || s[j] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length = length + 2;
			val = s[j];
			if (val < 16)
			{
				_putchar('0');
				length++;
			}
			length = length + printf_HEX_number(val);
		}
		else
		{
			_putchar(s[j]);
			length++;
		}
		j++;
	}
	return (length);
}
