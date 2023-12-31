#include "main.h"

/**
 * get_width - gets the width of the binary representation of a number
 * @format: formatted string to print the argument
 * @i: list of the argument to print
 * @list: list of arguments
 * Return: the width of the binary representation of a number
 */

	int get_width(const char *format, int *i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
		break;
	}
	*i = curr_i - 1;
return (width);
}
