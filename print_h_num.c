#include "main.h"

/**
 * printf_hex_number - Display a hexdecimal number.
 * @numb: input value.
 * Return: value.
 */
int printf_hex_number(unsigned long int numb)
{
	long int j;
	long int *array;
	long int value = 0;
	unsigned long int temp = numb;

	while (numb / 16 != 0)
	{
		numb /= 16;
		value++;
	}
	value++;
	array = malloc(sizeof(long int) * value);

	j = 0;

	while (j < value)
	{
		array[j] = temp % 16;
		temp = temp / 16;
		j++;
	}

	j = value - 1;

	while (j >= 0)
	{
		if (array[j] > 9)
		{
			array[j] = array[j] + 39;
		}
		_putchar(array[j] + '0');
		j--;
	}
	free(array);
	return (value);
}
