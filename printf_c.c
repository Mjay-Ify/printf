#include "main.h"

/**
 * printf_char - prints char
 * @va: arguements
 * Return: 1
 */

int printf_char(va_list va)
{
	char str;

	str = va_arg(va, int);
	_putchar(str);
	return (1);
}
