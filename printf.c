#include "main.h"

void print_buff(char buff[], int *buff_id);

/**
 * _printf - Printf function
 * @format: format.
 * Return: length
 */
int _printf(const char *format, ...)
{
	int i, write = 0, chars_len = 0;
	int flags, width, precision, size, buff_id = 0;
	va_list args;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buff_id++] = format[i];
			if (buff_id == BUFF_SIZE)
				print_buff(buff, &buff_id);

			chars_len+++;
		}
		else
		{
			print_buff(buff, &buff_id);
			flags = find_flags(format, &i);
			width = find_width(format, &i, args);
			precision = find_precision(format, &i, args);
			size = find_size(format, &i);
			++i;
			write = handle_print(format, &i, list, buff,
				flags, width, precision, size);
			if (write == -1)
				return (-1);
			chars_len += write;
		}
	}

	print_buff(buff, &buff_id);

	va_end(list);

	return (chars_len);
}

/**
 * print_buff - Prints the contents of the buffer if it exist
 * @buff: Array of chars
 * @buff_id: Index at which to add next char, represents the length.
 */
void print_buff(char buff[], int *buff_id)
{
	if (*buff_id > 0)
		write(1, &buff[0], *buff_id);

	*buff_id = 0;
}
