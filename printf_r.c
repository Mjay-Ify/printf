#include "main.h"

/**
 * print_rev - print in reverse
 * @args: parameter
 * Return: the length
 */

int print_rev(va_list args)
{
	char *s = va_arg(args, char*);
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	for (i = count - 1; i >= 0; i--)
		_putchar(s[i]);
	_putchar('\n');
	return (count);
}
