#include "main.h"

/* OUTPUT UNSIGNED NUMBER */
/**
 * output_unsigned - Displays unsigned number
 * @types: Arrays of arguments
 * @buffer: Buffer array to manage print
 * @flags: Indicate active status
 * @width: width's value
 * @precision: Precision specification
 * @size: the size specifier
 * Return: Count of chars printed.
 */
int output_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int count = va_arg(types, unsigned long int);

	count = convert_size_unsgnd(num, size);

	if (count == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (count > 0)
	{
		buffer[i--] = (count % 10) + '0';
		count /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* FUNCTION TO PRINT UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - Display an unsigned number in octal format
 * @data_types: Arrays of arguments
 * @buffer: Buffer array to manage print
 * @flags:  Indicate its active status
 * @width: width's value
 * @precision: Precision specification
 * @size: the size specifier
 * Return: Number of printed characaters
 */
int print_octal(va_list data_types, char buffer[],
	int flags, int width, int precision, int size)
{

	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(data_types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[j--] = '0';

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * output_hexadecimal - show an unsigned number in hex form.
 * @types: Arrays of arguments
 * @buffer: Buffer array to manage print
 * @flags: Indicate active flags
 * @width: width's value
 * @precision: Precision specification
 * @size: The size specifier
 * Return: count of characters printed
 */
int output_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (output_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* DISPLAY UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_upper_hex - Display unsigned number in upper hex form.
 * @data_types: arrays of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Indicate the  active flags
 * @width: width
 * @precision: Manage precision specification
 * @size: the size specifier
 * Return: Count of printed characters
 */
int print_upper_hex(va_list data_types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_upper(data_types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* Show hexadecimal number in upper or lower*/
/**
 * output_hex - Display hexa num in either upper or lower
 * @types: The list of arguments
 * @map_to: This is the array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Represents the active flags
 * @flag_ch: Represents the active flags
 * @width: gets width
 * @precision: Precision specification
 * @size: The size specifier
 * @size: The size specification
 * Return: Number of characters printed
 */
int output_hex(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
