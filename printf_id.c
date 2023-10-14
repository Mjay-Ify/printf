#include "main.h"

/**
 * print_number - print an integer
 * @args: parameter
 * Return: number of char printed
 */

int printf_int(va_list args)
{
	int n = va_arg(args, int);
	int i = 0;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}
	if ((i / 10) > 0)
		print_number(i / 10);
	_putchar((i % 10) + '0');
	return (i);
}

/**
 * print_dec - print an integer
 * @args: parameter
 * Return: num of chars print
 */

int print_dec(va_list args)
{
	int n = va_arg(args, int);
	int i = 0;

	if (n < 0)
	{
		_putchar('-');
		i = -i;
	}
	if ((i / 10) > 0)
		print_number(i / 10);
	_putchar((i % 10) + '0');
	return (i);
}
