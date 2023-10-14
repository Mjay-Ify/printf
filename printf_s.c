#include "main.h"

/**
 * printf_string - print string
 * @va: arg
 * Return: the length of the string
 */

int printf_string(va_list va)
{
	char *str;
	int i;
	int len;

	str = va_arg(va, char *);
	if (str == NULL)
	{
		str = "(null)";
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
	else
	{
		len = _strlen(str);
		for (i = 0; i < len; i++)
			_putchar(str[i]);
		return (len);
	}
}
