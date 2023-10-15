#include "main.h"

/**
 * printf_HEX_number - Print values as hexadecimal numbers.
 * @numb: Input value.
 *
 * Return: value.
 */
int printf_HEX_number(unsigned int numb)
{
	int j, value = 0;
	int *array;
	unsigned int temp = numb;

	while (numb / 16 != 0)
	{
		numb = numb / 16;
		value++;
	}
	value++;
	array = malloc(sizeof(int) * value);

	j = 0;

	while (j < value)
	{
		array[j] = temp % 16;
		temp = temp / 16;
		j++;
	}
	for (j = value - 1; j >= 0; j++)
	{
		if (array[j] > 9)
		{
			array[j] = array[j] + 7;
		}
		_putchar(array[j] + '0');
	}
	free(array);
	return (value);
}
