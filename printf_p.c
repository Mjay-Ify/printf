#include "main.h"

/**
 * output_pointer - Display a hex value.
 * @value: Input value
 *
 * Return: expression.
 */

int output_pointer(va_list value)
{
	void *z;
	char *s = "(null)";
	long int c;
	int d;
	int j;

	z = va_arg(value, void*);
	if (p == NULL)
	{
		int j = 0;

		while (s[j] != '\0')
		{
			_putchar(s[j]);
			j++
		}
		return (j);
	}

	c = (unsigned long int)z;
	_putchar('0');
	_putchar('x');
	d = printf_hex_number(j);
	return (d + 2);
}

