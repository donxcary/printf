#include "main.h"

/*************************Handle Width*************************/
/**
 * handle_width - handle width
 * @buff: buffer
 * @width: width
 * @flags: flags
 * @precision: precision
 * @size: size
 * Return: number of characters printed
 */
int handle_width_char(char* buff, int width, int flags, int precision, int size)
{
	int count = 0;
	int ind = 0;

	if (flags & F_MINUS)
	{
		count += handle_precision_char(buff, precision, size);
		count += handle_width(buff, width, flags, precision, size);
	}
	else
	{
		count += handle_width(buff, width, flags, precision, size);
		count += handle_precision_char(buff, precision, size);
	}
	return (count);
}

/*************************Handle Write Number*************************/
/**
 * handle_write_number - handle write number
 * @num: number
 * @buff: buffer
 * @i: index
 * @flags: flags
 * @width: width
 * @precision: precision
 * @size: size
 * Return: number of characters printed
 */
	int handle_write_number(int is_positive, int ind, char* buff, int width, int flags, int precision, int size)
{
		int count = 0;

		if (flags & F_MINUS)
		{
			if (is_positive)
				count += _write_char('+', buff, &ind);
			else
				count += _write_char('-', buff, &ind);
			count += handle_width_char(buff, width, flags, precision, size);
		}
		else
		{
			if (flags & F_ZERO)
			{
				if (is_positive)
					count += _write_char('+', buff, &ind);
				else
					count += _write_char('-', buff, &ind);
				count += handle_width_char(buff, width, flags, precision, size);
			}
			else
			{
				count += handle_width_char(buff, width, flags, precision, size);
				if (is_positive)
					count += _write_char('+', buff, &ind);
				else
					count += _write_char('-', buff, &ind);
			}
		}
		return (count);
	}

	/*************************Handle Precision Char*************************/
/**
	 * handle_precision_char - handle precision char
	 * @buff: buffer
	 * @precision: precision
	 * @size: size
	 * Return: number of characters printed
	 */
int handle_precision_char(char* buff, int precision, int size)
{
	int count = 0;
	int ind = 0;

	if (precision > size)
	{
		while (ind < precision - size)
		{
			count += _write_char('0', buff, &ind);
		}
	}
	return (count);
}