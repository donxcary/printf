#include "main.h"

/**
 * get_precision - get precision
 * @format: format
 * @i: index
 * @args: arguments
 * Return: precision
 */
int handle_wirte_num(int ind, char* buff, int width, int flags, int precision, int length, char padd, char extra_c)
{
	int count = 0;

	if (flags & F_MINUS)
	{
		count += handle_precision_char(buff, precision, length);
		count += handle_width(buff, width, flags, precision, length);
	}
	else
	{
		count += handle_width(buff, width, flags, precision, length);
		count += handle_precision_char(buff, precision, length);
	}
	return (count);
}

/**
 * handle_write_pointer - handle write pointer
 * @num: number
 * @buff: buffer
 * @i: index
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 *	Return: number of characters printed
 */
int handle_wirte_pointer(int ind, char* buff, int width, int flags, int length, char padd, char extra_c, int padd_start)
{
	int count = 0;

	if (flags & F_MINUS)
	{
		count += _write_char('0', buff, &ind);
		count += _write_char('x', buff, &ind);
		count += handle_precision_char(buff, width, length);
		count += handle_width(buff, width, flags, width, length);
	}
	else
	{
		count += handle_width(buff, width, flags, width, length);
		count += _write_char('0', buff, &ind);
		count += _write_char('x', buff, &ind);
		count += handle_precision_char(buff, width, length);
	}
	return (count);
}

/**
 * handle_write_unsigned - handle write unsigned
 * @num: number
 * @buff: buffer
 * @i: index
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of characters printed
 */
int handle_write_unsigned(int is_negative, int ind, char* buff, int width, int flags, int precision, int size)
{
	int count = 0;

	if (flags & F_MINUS)
	{
		if (is_negative)
			count += _write_char('-', buff, &ind);
		count += handle_precision_char(buff, precision, size);
		count += handle_width(buff, width, flags, precision, size);
	}
	else
	{
		count += handle_width(buff, width, flags, precision, size);
		if (is_negative)
			count += _write_char('-', buff, &ind);
		count += handle_precision_char(buff, precision, size);
	}
	return (count);
}

/**
 * is_printable - check if char is printable
 * @c: char
 * Return: 1 if printable, 0 otherwise
 */
 int is_printable(char)
{
return (c >= 32 && c <= 126);
}

/**
* append_hex_code - append hex code
* @c: char
* @buff: buffer
* @i: index
* Return: number of characters printed
*/
 int append_hex_code(char, char*, int)
{
	int count = 0;

	count += _write_char('\\', buff, i);
	count += _write_char('x', buff, i);
	count += _write_char('0', buff, i);

	if (c < 16)
		count += _write_char('0', buff, i);
		count += _write_hex(c, buff, i, 0);
	return (count);
}

/**
* is_digit - check if char is digit
* 
* Return: 1 if digit, 0 otherwise
*/ 
 int is_digit(char)
 {
		return (c >= '0' && c <= '9');
 }

/**
* long int convert_size_number - convert size number
* @num: number
* @size: size
* Return: converted number
*/
 long int convert_size_number(long int num, int size)
 {
if (size == 0)
			return ((char)num);
		else if (size == 1)
			return ((short int)num);
		else if (size == 2)
			return ((long int)num);
		else if (size == 3)
			return ((long long int)num);
		else
			return (num);
 }

 long int convert_size_unsigned_number(unsigned long int num, int size)
 {
if (size == 0)
			return ((unsigned char)num);
		else if (size == 1)
			return ((unsigned short int)num);
		else if (size == 2)
			return ((unsigned long int)num);
		else if (size == 3)
			return ((unsigned long long int)num);
		else
			return (num);
 }

