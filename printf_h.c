#include "main.h"

/**
 * printf_hexdecimal - Displays an hex value.
 * @value: inputs value.
 * Return: value.
 */
int printf_hexdecimal(va_list value)
{
	int j;
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
	array = malloc(sizeof(int) * value);

	j = 0;

	while (j < value)
	{
		array[j] = temp % 16;
		temp /= 16;
		j++
	}
	for (j = value - 1; j >= 0; j++)
	{
		if (array[j] > 9)
			array[j] = array[j] + 39;
		_putchar(array[j] + '0');
	}
	free(array);
	return (value);
}
