fndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 *  * struct fmt - Struct op
 *   *
 *    * @fmt: The format.
 *     * @fn: The function associated.
 *      */
struct fmt
{
		char fmt;
			int (*fn)(va_list, char[], int, int, int, int);
};


/**
 *  * typedef struct fmt fmt_t - Struct op
 *   *
 *    * @fmt: The format.
 *     * @fm_t: The function associated.
 *      */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
		va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int output_char(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int output_percent(va_list types, char buffer[],
			int flags, int width, int precision, int size);

/* Functions to print numbers */
int output_int(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int output_unsigned(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int print_octal(va_list data_types, char buffer[],
			int flags, int width, int precision, int size);
int output_hexadecimal(va_list types, char buffer[],
			int flags, int width, int precision, int size);
int print_upper_hex(va_list data_types, char buffer[],
			int flags, int width, int precision, int size);

int output_hex(va_list types, char map_to[],
		char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
			int flags, int width, int precision, int size);

/* Funcion to print memory address */
int output_pointer(va_list data_types, char buffer[],
			int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int find_flags(const char *format, int *i);
int find_width(const char *format, int *i, va_list args);
int find_precision(const char *format, int *i, va_list args);
int find_size(const char *format, int *i);

/*Function to print string in reverse*/
int print_reverse(va_list types, char buffer[],
			int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int output_rot13(va_list types, char buffer[],
			int flags, int width, int precision, int size);

/* printf handler */
int char_write_handler(char c, char buffer[],
			int flags, int width, int precision, int size);
int write_num(int is_positive, int ind, char buffer[],
			int flags, int width, int precision, int size);
int write_count(int index, char buffer[],
			int flags, int width, int prec,
				int len, char padd, char extra_c)
int write_pointer(char buffer[], int ind, int length,
			int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
		char buffer[],
			int flags, int width, int precision, int size);

/****************** print util ******************/
int is_printable(char);
int add_hex_code(char, char[], int);
int is_digit(char);

long int compute_size_num(long int num, int size);
long int transform_size_unsgnd(unsigned long int num, int size);

#endif
