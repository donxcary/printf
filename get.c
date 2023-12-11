#include "main.h"

/*************************Get Flags*************************/
/**
 * get_flags - get flags
 * @format: format
 * @i: index
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;

	while (format[*i])
	{
		if (format[*i] == ' ')
			flags |= SPACE_FLAG;
		else if (format[*i] == '+')
			flags |= PLUS_FLAG;
		else if (format[*i] == '#')
			flags |= HASH_FLAG;
		else if (format[*i] == '-')
			flags |= MINUS_FLAG;
		else if (format[*i] == '0')
			flags |= ZERO_FLAG;
		else
			break;
		(*i)++;
	}
	return (flags);
}

/*************************Get Width*************************/
/**
 * get_width - get width
 * @format: format
 * @i: index
 * @args: arguments
 * Return: width
 */
int get_width(const char *format, int *i, va_list args)
{
	int width = 0;

	while (format[*i])
	{
		if (format[*i] == '*')
		{
			width = va_arg(args, int);
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			width = _atoi(format, i);
		}
		else
			break;
	}
	return (width);
}

/*************************Get Precision*************************/
/**
 * get_precision - get precision
 * @format: format
 * @i: index
 * @args: arguments
 * Return: precision
 */
int get_precision(const char *format, int *i, va_list args)
{
	int precision = 0;

	if (format[*i] == '.')
	{
		(*i)++;
		if (format[*i] == '*')
		{
			precision = va_arg(args, int);
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			precision = _atoi(format, i);
		}
		else
			precision = 0;
	}
	return (precision);
}

/*************************Get Size*************************/
/**
 * get_size - get size
 * @format: format
 * @i: index
 * Return: size
 */
int get_size(const char *format, int *i)
{
	int size = 0;

	while (format[*i])
	{
		if (format[*i] == 'h')
			size |= H_SIZE;
		else if (format[*i] == 'l')
			size |= L_SIZE;
		else
			break;
		(*i)++;
	}
	return (size);
}