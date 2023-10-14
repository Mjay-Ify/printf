#include "main.h"

/**
 * _strlen - length of string
 * @s: parameter
 * Return: length of string
 */

int _strlen(char *str)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}

/**
 * _strlen - length of string
 * @s: parameter
 * Return: length of string
 */

int _strlenc(const char *s)
{
	int i;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}
