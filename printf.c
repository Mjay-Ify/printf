#include "main.h"

/**
 * _printf - mimics printf
 * @format: identifier look for
 *
 * Return: integer
 */
int _printf(const char *format, ...)
{
	myconversion i[] = {
		{"%c", printf_char}, 
		{"%s", printf_string},
	       	{"%%", printf_37},
	       	{"%d", printf_dec},
	       	{"%b", printf_bin},
	       	{"%u", printf_unsigned},
	       	{"%i", printf_int},
		{"%r", printf_rev},
		{"%R", printf_rot13},
	       	{"%o", printf_oct},
	       	{"%S", printf_string_excl},
	       	{"%p", output_pointer},
	       	{"%x", printf_hexdecimal},
	       	{"%X", printf_HEXDECIMAL}

	va_list args;
	int j = 0, length = 0;
	int k;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

mylabel:

	while (format[j] != '\0')
	{
		k = 13;
		while(k >= 0)
		{
			if (i[k].name[0] == format[j] && i[k].name[j] == format[j + 1])
			{
				length = length + i[k].operation(args);
				j = j + 2;
				goto mylabel;
			}
			k--;
		}
		_putchar(format[j]);
		j++;
		length++;
	}
	va_end(args);
	return (length);
}
