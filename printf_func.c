#include "main.h"

/* OUTPUT CHAR */

/**
 * output_char - Displays a char.
 @ data_types: Arrays of arguments
 @ buffer: Buffer array to manage print
 @ flags: calculate active flags.
 @ width: width's value.
 @ size: The size specifier.
 @ precision: the precision specifier
  *Return: count of chars printed
 */
int output_char(va_list data_types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(data_types, int);

	return (char_write_handler(c, buffer, flags, width, precision, size));
}
/* FUNCTION TO OUTPUT A STRING */
/**
 * print_string - Display a string
 * @data_types:  Arguments list.
 * @buffer: Buffer array to manage print
 * @flags:  Denotea active flags
 * @width:  width's value.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: Count of printed characters
 */
int print_string(va_list data_types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, j;
	char *str = va_arg(data_types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - len; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/* PERCENT SIGN */
/**
 * output_percent - Displays percent's sign
 * @types: array of arguments
 * @buffer: Buffer array to manage print
 * @flags: active flags
 * @width: value width.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: count of characters printed
 */
int output_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/** DISPLAY INT **/
/**
 * output_int - output int
 * @types: array of arguments
 * @buffer: Buffer array to manage print
 * @flags:  Flags that are active.
 * @width: value ofwidth.
 * @precision: The precision specification
 * @size: Specification of data size
 * Return: count of printed characters.
 */
int output_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int count;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	count = (unsigned long int)n;

	if (n < 0)
	{
		count = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (count > 0)
	{
		buffer[i--] = (count % 10) + '0';
		count /= 10;
	}

	i++;

	return (write_count(is_negative, i, buffer, flags, width, precision, size));
}

/* BINARY */
/**
 * print_binary - Display unsigned number
 * @types: Array of arguments
 * @buffer: Buffer array to handle print
 * @flags:  the active flags
 * @width: width's value.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: Count of characters printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, j, sum;
	unsigned int a[32];
	int num;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (j = 1; j < 32; j++)
	{
		m /= 2;
		a[j] = (n / m) % 2;
	}
	for (j = 0, sum = 0, num = 0; j < 32; j++)
	{
		sum += a[j];
		if (sum || j == 31)
		{
			char z = '0' + a[j];

			write(1, &z, 1);
			num++;
		}
	}
	return (num);
}
