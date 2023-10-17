#include "main.h"

/**
 * output_pointer - Display a hex value.
 * @value: Input value
 *
 * Return: expression.
 */

int output_pointer(va_list value)
{
	void *p;
	char *s = "(nil)";
	long int c;
	int j, d;

	p = va_arg(value, void*);
	if (p == NULL)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			_putchar(s[j]);
		}
		return (j);
	}

	c = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	d = printf_hex_number(c);
	return (d + 2);
}

