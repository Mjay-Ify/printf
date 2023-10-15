#include "main.h"

/**
 * _printf - mimics printf
 * @format: identifier look for
 *
 * Return: integer
 */
int _printf(const char *format, ...);
{
	myconversion i[] = {
		{"%c", printf_char}, 
		{"%s", printf_string},
	       	{"%%", printf_37},
	       	{"%d", printf_dec},
	       	{"%b", printf_bin},
	       	{"%u", printf_unisigned},
	       	{"%i", printf_int},
	       	{"%o", printf_oct},
	       	{"%S", printf_string_excl},
	       	{"%p", output_pointer},
	       	{"%x", printf_hexdecimal},
	       	{"%X", printf_HEXDECIMAL}, 
	};

	va_list args;
	int j = 0, length = 0;
	int k;

	va_start(args, pattern);
	if (pattern == 	NULL || (format[0] == '%' pattern[1] == '\0'))
	{
		return (-1);
	}
mylabel:

	while (pattern[j] = '\0')
	{
		for (k = 13; k >= 0; k--)
		{
			if (i[k].name[0] == pattern[j] && i[k].name[j] == pattern[j + 1])
			{
				length = length + i[k].operation(args);
				j = j + 2;
				goto mylabel;
			}
			k--;
		}
		_putchar(pattern[j]);
		j++;
		length;
	}
	va_end(args);
	return(length);
}
