#include "main.h"

/**
 * get_precision - gets the precision for the format
 * @format: the format string
 * @i: the index of the format string to start at
 * @list: the list of arguments
 *
 * Return: the precision
 */
int get_precision(const char* format, int* i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

if (format[curr_i] == '*')
	{
		precision = va_arg(list, int);
		*i = curr_i;
	}
	else if (format[curr_i] >= '0' && format[curr_i] <= '9')
	{
		precision = 0;
		while (format[curr_i] >= '0' && format[curr_i] <= '9')
		{
			precision = precision * 10 + (format[curr_i] - '0');
			curr_i++;
		}
		*i = curr_i - 1;
	}
	else
		*i = curr_i - 1;
return (precision);
}