#include "main.h"

/* OUTPUT POINTER */
/**
 * output_pointer - Displays value of pointer variable
 * @types: Arrays of arguments
 * @buffer: Buffer array to handle print
 * @flags: INdicate active flags
 * @width: width's value.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Count of printed character.
 */
int output_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFF_SIZE - 2, len = 2, padd_start = 1; /* len=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', len++;
	else if (flags & F_SPACE)
		extra_c = ' ', len++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, len,
		width, flags, padd, extra_c, padd_start));
}

/* PRINT NON PRINTABLE */
/**
 * print_non_printable - Display hex ASCII code of non-printable char
 * @data_types: Arrays of an arguments
 * @buffer: Buffer array to manage print
 * @flags:  Indicate active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num of printed character.
 */
int print_non_printable(va_list data_types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[i]))
			buffer[j + offset] = str[j];
		else
			offset += append_hexa_code(str[j], buffer, j + offset);

		j++;
	}

	buffer[j + offset] = '\0';

	return (write(1, buffer, j + offset));
}
/* PRINT REVERSE */
/**
 * print_reverse - Show the reverse string.
 * @types: Indicate the array of arguments
 * @buffer: Buffer array to manage print
 * @flags:  Active flags
 * @width: width's value
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Num of chars to print.
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int j, counter = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (j = 0; str[j]; j++)
		;

	for (j = j - 1; j >= 0; j--)
	{
		char z = str[j];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}
/* OUTPUT A STRING IN ROT13 */
/**
 * output_rot13 - display string in rot13.
 * @types: represents the array of arguments
 * @buffer: Buffer array to handle print
 * @flags:  indicate its active status
 * @width: value of width
 * @precision: Precision specification
 * @size: the Size specifier
 * Return: Numbers of chars to print
 */
int output_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
