#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct pattern - Corresponding to the printf conversion specifiers
 * @name: A pointer to char for integer format options for (d, i, u, o, x, X)
 *
 * @operation: A specifier-handling function pointer.
 *
 */
typedef struct format
{
	char *name;
	int (*operation)();
} myconversion;

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);
int _strlen(char *s);
int _strlenc(const char *s);
int printf_37(void);
int printf_int(va_list args);
int printf_dec(va_list args);
int printf_bin(va_list args);
int printf_unsigned(va_list args);
int printf_oct(va_list args);
int printf_string_excl(va_list value);
int printf_HEX_number(unsigned int numb);
int printf_hex_number(unsigned long int numb);
int printf_hexdecimal(va_list value);
int printf_HEXDECIMAL(va_list value);
int output_pointer(va_list value);
int printf_rev(va_list args);
int printf_rot13(va_list args);
int short_i(va_list);
int long_i(va_list);
int case_l(unsigned long int val);
int case_u(unsigned long int val);
int checker(char c, char flags[], int l);
int flag_checker(char f, long int dig, char func);

	
#endif