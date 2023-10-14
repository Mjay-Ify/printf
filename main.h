#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list va);
int printf_string(va_list va);
int _strlen(char *str);
int _strlenc(const char *str);
int print_37(void);
int printf_int(va_list args);
int printf_dec(va_list args)

#endif
