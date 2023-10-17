#include "main.h"

/**
 * _printf - Printf function emulation.
 * @format: The identifier to locate within the code.
 *
 * Return: integer
 */
int _printf(const char * const format, ...)
{
	myconversion c[] = {
		{"%c", printf_char}, {"%s", printf_string}, {"%%", printf_37},
		{"%d", printf_dec}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%i", printf_int}, {"%r", printf_rev}, {"%R", printf_rot13},
		{"%o", printf_oct}, {"%S", printf_string_excl},
		{"%p", output_pointer}, {"%x", printf_hexdecimal}, {"%X", printf_HEXDECIMAL}
	};

	va_list args;
	int i = 0, length = 0;
	int j;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

my_label:

	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (c[j].name[0] == format[i] && c[j].name[1] == format[i + 1])
			{
				length = length + c[j].operation(args);
				i = i + 2;
				goto my_label;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		length++;
	}
	va_end(args);
	return (length);
}
