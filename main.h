#ifndef MAIN_H
#define MAIN_H
#include <stdarg.>
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
 * struct fmt - struct op
 * @op: operator
 * @fmt: The format
 * @fn: The function associated
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char *, unsigned int, int, int, int, int);
};

/**
* typedef struct fmt fmt_t - struct op
* 
* @fmt: The format
* @fmt_t: The function associated
*/
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *format, va_list args, char *buff, unsigned int *i);
int _write_buffer(char *buff, unsigned int *i);
int _write_char(char c, char *buff, unsigned int *i);
int _write_string(char *str, char *buff, unsigned int *i);
int _write_number(int num, char *buff, unsigned int *i);
int _write_unsigned(unsigned int num, char *buff, unsigned int *i);
int _write_hex(unsigned int num, char *buff, unsigned int *i, int is_upper);
int _write_octal(unsigned int num, char *buff, unsigned int *i);

/************************* functions ************************/
/* functions to print chars and strings */
int print_char(va_list types, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_string(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_percent(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);

/* functions to print numbers */
int print_int(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_unsigned(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_octal(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_hex(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_hex_upper(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_binary(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);

/* functions to print non printable char */
int print_non_printable(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);

/* functions to print memory address */
int print_pointer(va_list args, char *buff, unsigned int i, int flags, int width, int precision, int size);

/* functions to handle other specifier */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/* functions to print string in reverse */
int print_rev_string(va_list types, char *buff, unsigned int i, int flags, int width, int precision, int size);
int print_reverse(va_list types, char *buff, unsigned int i, int flags, int width, int precision, int size);

/* functions to print a string in rot13 */
int print_rot13sting(va_list types, char *buff, unsigned int i, int flags, int width, int precision, int size);

/* Width handler */
int handle_width_char(char *buff, int width, int flags, int precision, int size);
int handle_write_number(int is_positive, int ind, char *buff, int width, int flags, int precision, int size);
int handle_precision_char(char *buff, int precision, int size);
int handle_wirte_num(int ind, char *buff, int width, int flags, int precision, int length, char padd, char extra_c);
int handle_wirte_pointer(int ind, char *buff, int width, int flags, int length, char padd, char extra_c,int padd_start);
int handle_write_unsigned(int is_negative, int ind, char *buff, int width, int flags, int precision, int size);

/************************* UTILS *************************/
int is_printable(char);
int append_hex_code(char, char*, int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsigned_number(unsigned long int num, int size);)
#endif /* MAIN_H */
