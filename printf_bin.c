#include "main.h"

/**
 * printf_bin - convert to binary
 * @args: arg
 * Return: int	
 */

int printf_bin(va_list args)
{
	int flag = 0, count = 0, a = 1;
	int i, b;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int j;

	for (i = 0; i < 32; i++)
	{
		j = ((a << (32 - i)) & num);
		if (j >> (31 - i))
			flag = 1;
		if (flag)
		{
			b = j >> (31 - i);
			_putchar(b + '0');
			count++;
		}
	}
	if (count == 0)
	{
		count++;
		_putchar('0');
	}
	return (count);
}
