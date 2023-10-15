#include "main.h"

/**
 * printf_HEX - converts to hex
 * @args: arg
 * Return: count
 */

int printf_HEX(va_list args)
{
	int i, count = 0;
	int *array;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int tmp = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		count++;
	}
	count++;
	array = malloc(sizeof(int) * count);

	for (i = 0; i < count; i++)
	{
	array[i] = tmp % 16;
	tmp = tmp / 16;
	}
	for (i = count - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (count);
}	
