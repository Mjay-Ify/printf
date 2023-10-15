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

	for (c = 0; c < val; c++)
	{
		array[c] = temp % 16;
		temp = temp / 16;
	}
	for (c = val - 1; c >= 0; c--)
	{
		if (array[c] > 9)
			array[c] = array[c] + 7;
		_putchar(array[c] + '0');
	}
	free(array);
	return (val);
}
