#include "main.h"

/**
 * _strlen - length of string
 * @s: parameter
 * Return: length of string
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strlenc - length of string
 * @s: parameter
 * Return: length of string
 */

int _strlenc(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
