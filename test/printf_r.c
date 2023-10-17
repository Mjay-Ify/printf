#include "main.h"

/**
 * printf_rev - print in reverse
 * @args: parameter
 *
 * Return: the length
 */

int printf_rev(va_list args)
{
	char *s = va_arg(args, char*);
	int i;
	int count = 0;

	if (s == NULL)
		s = "(null)";
	while (s[count] != '\0')
		count++;
	for (i = count - 1; i >= 0; i--)
		_putchar(s[i]);
	return (count);
}
