#include "main.h"

/**
 * _printf - prints anything
 * @format: list of arguments passed to the function
 * Return: number of characters printed
 */
int _printf(const char* format, ...)
{
	return 0;
}

/**
 * handle_print - handles the printing of the format
 * @format: list of arguments passed to the function
 * @args: list of arguments passed to the function
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int handle_print(const char* format, va_list args, char* buff, unsigned int* i)
{
	return 0;
}

/**
 * _write_buffer - writes the buffer to stdout
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int _write_buffer(char* buff, unsigned int* i)
{
	return 0;
}

/**
 * _write_char - writes a character to the buffer
 * @c: character to write
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int _write_char(char c, char* buff, unsigned int* i)
{
	return 0;
}

/**
 * _write_string - writes a string to the buffer
 * @str: string to write
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int _write_string(char* str, char* buff, unsigned int* i)
{
	return 0;
}

/**
 * _write_number - writes a number to the buffer
 * @num: number to write
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int _write_number(int num, char* buff, unsigned int* i)
{
	return 0;
}

/**
 * _write_unsigned - writes an unsigned number to the buffer
 * @num: number to write
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int _write_unsigned(unsigned int num, char* buff, unsigned int* i)
{
	return 0;
}

/**
 * _write_hex - writes a hexadecimal number to the buffer
 * @num: number to write
 * @buff: buffer to store the string
 * @i: index of the buffer
 * @is_upper: flag to print uppercase
 * Return: number of characters printed
 */
int _write_hex(unsigned int num, char* buff, unsigned int* i, int is_upper)
{
	return 0;
}

/**
 * _write_octal - writes an octal number to the buffer
 * @num: number to write
 * @buff: buffer to store the string
 * @i: index of the buffer
 * Return: number of characters printed
 */
int _write_octal(unsigned int num, char* buff, unsigned int* i)
{
	return 0;
}
