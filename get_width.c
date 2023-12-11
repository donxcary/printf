#include "main.h"

/**
 * get_width - gets the width of the binary representation of a number
 * @format: formatted string to print the argument
 * @i: list of the argument to print
 * Return: the width of the binary representation of a number
 */
int get_width(const char* format, int* i, va_list list)
{
	int curr_i;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (format[curr_i] == '*')
		{
			width = va_arg(list, int);
			*i = curr_i;
			return (width);
		}
		else if (format[curr_i] >= '0' && format[curr_i] <= '9')
		{
			width = width * 10 + (format[curr_i] - '0');
		}
		else
		{
			*i = curr_i - 1;
			return (width)
}
}
	*i = curr_i - 1;
	return (width);
}