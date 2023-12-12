#include "main.h"

/************************* Is Printable *************************/
/**
* is_printable - checks if a character is printable
* @c: character to check
* Return: 1 if c is printable, 0 otherwise
*/
int is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

/************************* Append Hexa *************************/
/**
* append_hexa_code - appends a hexa code to a buffer
* @buffer: array of characters
* @i: index at which to start appending
* @ascii_code: ascii code to append
* Return: always 3
*/
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/************************* Convert Size Unsigned *************************/
/**
* convert_size_unsgnd - cast a number to specified size
* @num: number to cast
* @size: number indicating the type of casting
*
* Return: the casted number
*/
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/************************* Convert Size Number *************************/
/**
* convert_size_number - cast a number to specified size
* @num: number to cast
* @size: number indicating the type of casting
*
*
* Return: the casted number
*/
	long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/************************* Is Digit *************************/
/**
* is_digit - checks if a character is a digit
* @c: character to check
*
* Return: 1 if c is a digit, 0 otherwise
*/
	int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}
