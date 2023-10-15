#include "main.h"

/**
 * printf_HEXDECIMAL - prints hex value.
 * @value: Input argument
 * Return: Value.
 */
int printf_HEXDECIMAL(va_list value)
{
	int c;
	int *array;
	int value = 0;
	unsigned int num = va_arg(value, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		value++;
	}
	value++;
	array = malloc(value * sizeof(int));

	c = 0;
	while (c < value)
	{
		array[c] = temp % 16;
		temp /= 16;
		c++
	}
	for (c = value - 1; c >= 0; c++)
	{
		if (array[c] > 9)
			array[c] = array[c] + 7;
		_putchar(array[c] + '0');
	}
	free(array);
	return (value);
}
