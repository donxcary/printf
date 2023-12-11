#include "main.h"

/**
 * get_size - calculates the size to cast the argumen
 * @format: formatted string to print with the arguments
 * @i: index of the format string
 * @args: list of arguments to be printed
 * Return: size of the argument
 */
int get_size(const char* format, int* i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
	else if (format[curr_i] == 'L')
		size = S_LDOUBLE;
	else
		size = 0;
	*i = curr_i;
	return (size);
}