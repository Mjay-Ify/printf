#include "main.h"

/**
 * is_printable - Determine if a character is displayble
 * @c:the character
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * add_hex_code - appends the ascii in hexadecimal code to buffer
 * @buffer: Lists of characters
 * @i: Index to start from.
 * @ascii_code: THE ASSCI CODE.
 * Return: Always 3
 */
int add_hex_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - confirm if the character is a digit
 * @c: Character
 *
 * Return: 1 if c is a digit, else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * compute_size_num - adds a number to the designated size
 * @num: value for addition.
 * @size: represents the type to be added.
 *
 * Return: Added input of num
 */
long int compute_size_num(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * transform_size_unsgnd - Casts a number to the specified size
 * @count: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int transform_size_unsgnd(unsigned long int count, int size)
{
	if (size == S_LONG)
		return (count);
	else if (size == S_SHORT)
		return ((unsigned short)count);

	return ((unsigned int)count);
}
