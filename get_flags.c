#include "main.h"

/************************ Get Flags *************************/

/* This function gets the flags from the flags file and      */

/**
* get_flags - gets the flags from the flags file
* @format: format string
* @i: take a perameter
* Return: flags
*/
int get_flags(const char* format, int* i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int flags = 0;
	int j, curr_i;
	const char FLAGS_CH[] = "-+0 #";
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i; format[curr_i]; curr_i++)
	{
		for (j = 0; FLAGS_CH[j]; j++)
		{
			if (format[curr_i] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		}
		if (!FLAGS_CH[j])
			break;
	}
*i = curr_i;
return (flags);
}