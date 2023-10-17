#include "main.h"

/* WRITE HANDLE */
/**
 * char_write_handle - displays a string
 * @c: character
 * @buffer: Buffer array to manage print
 * @flags: Indicate active flags.
 * @width:  width.
 * @precision: precision specifier
 * @size: Size
 *
 * Return: Num of printed character.
 */
int char_write_handler(char c, char buffer[],
	int flags, int width, int precision, int size)
{ /* character is kept at left and padding at buffer's right */
	int j = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[j++] = c;
	buffer[j] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (j = 0; j < width - 1; j++)
			buffer[BUFF_SIZE - j - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - j - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - j - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/* FUNCTION TO WRITE NUMBER */
/**
 * write_num - Show string
 * @is_negative: arrays of arguments
 * @index: char types.
 * @buffer: Buffer array to manage print
 * @flags: indicate its active status.
 * @width: width's value.
 * @precision: precision specifier
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int write_num(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - index - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_count(index, buffer, flags, width, precision,
		len, padd, extra_ch));
}

/**
 * write_count - Write counter using a bufffer
 * @index: Index where num starts
 * @buffer: represent Buffer array
 * @flags: active Flags
 * @width: width
 * @prec: Precision specifier
 * @len: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: count of printed chars.
 */
int write_count(int index, char buffer[],
	int flags, int width, int prec,
	int len, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no character is printed */
	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
		buffer[--index] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[index], len - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], len));
}

/**
 * write_unsgnd - Write an unsigned number
 * @is_negative: show if the number is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width
 * @precision: Precision specifier
 * @size: The size specifier
 *
 * Return: Number of written chars.
 */
int write_unsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Will write a memory address
 * @buffer: Arrays of chars
 * @ind: Indicates where the number starts in buffer
 * @len: Length
 * @width: Width
 * @flags: indctate its active status.
 * @padd: Char which represents the padding
 * @extra_c: represents extra char, also a char
 * @padd_start: Index at which padding starts
 *
 * Return: Count of character written.
 */
int write_pointer(char buffer[], int ind, int len,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buffer[j] = padd;
		buffer[j] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[3], j - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[ind], len));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], j - padd_start) +
				write(1, &buffer[ind], len - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
