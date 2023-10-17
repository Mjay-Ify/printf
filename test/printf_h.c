#include "main.h"

/**
 * printf_hexdecimal - Displays an hex value.
 * @value: inputs value.
 *
 * Return: value.
 */
int printf_hexdecimal(va_list value)
{
	int j;
	int *array;
	int val = 0;
	unsigned int num = va_arg(value, unsigned int);
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		val++;
	}
	val++;
	array = malloc(sizeof(int) * val);

	for (j = 0; j < val; j++)
	{
		array[j] = temp % 16;
		temp = temp / 16;
	}
	for (j = val - 1; j >= 0; j--)
	{
		if (array[j] > 9)
			array[j] = array[j] + 39;
		_putchar(array[j] + '0');
	}
	free(array);
	return (val);
}
