#include "main.h"

/**
 * printf_oct - converts to octa
 * @args: arg
 * Return: count
 */

int printf_oct(va_list args)
{
	int i, count = 0;
	int *array;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int tmp = num;

	while (num / 8 != 0)
	{
		num = num / 8;
		count++;
	}
	count++;
	array = malloc(sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
		array[i] = tmp % 8;
		tmp = tmp / 8;
	}
	for (i = count - 1; i >= 0; i--)
		_putchar(array[i] + '0');
	free(array);
	return (count);
}
