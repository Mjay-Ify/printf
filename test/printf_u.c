#include "main.h"

/**
 * printf_unsigned - prints unsigned int
 * @args: arg
 * Return: number of char print
 */

int printf_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int num, digit;
	int last = n % 10;
	int i = 1, exp = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}
