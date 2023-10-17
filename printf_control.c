#include "main.h"
/**
 * printf_control - Prints an argument based on its type
 * @format: Formatt  arguments.
 * @args: List of arguments to be printed.
 * @ind: id.
 * @buff: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int printf_control(const char *format, int *id, va_list args, char buff[],
	int flags, int width, int precision, int size)
{
	int i, len = 0, chars_len = -1;
	fmt_t fmt_types[] = {
		{'c', output_char}, {'s', print_string}, {'%', output_percent},
		{'i', output_int}, {'d', output_int}, {'b', print_binary},
		{'u', output_unsigned}, {'o', print_octal}, {'x', output_hexadecimal},
		{'X', print_upper_hex}, {'p', printf_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', output_rot13}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*id] == fmt_types[i].fmt)
			return (fmt_types[i].fn(args, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*id] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*id - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*id);
			while (fmt[*id] != ' ' && fmt[*id] != '%')
				--(*id);
			if (fmt[*id] == ' ')
				--(*id);
			return (1);
		}
		len += write(1, &fmt[*id], 1);
		return (len);
	}
	return (chars_len);
}

