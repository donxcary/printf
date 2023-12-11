#include "main.h"

/*************************Print Char*************************/

/**
 * print_char - prints a char
 * @type: list of arguments
 * buffer: buffer array to handle print
 * @flags: Calcutate active flags
 * width: width
 * precision: precision specification
 * size: size specification
 * Return: number of characters printed
 */
int print_char(va_list types, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	buff[i] = c;
	return (1);
}

/*************************Print String*************************/
/**
 * print_string - prints a string
 * @type: list of arguments
 * buffer: buffer array to handle print
 * @flags: Calcutate active flags
 * width: width
 * precision: precision specification
 * size: size specification
 * Return: number of characters printed
 */
int print_string(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
char *str = va_arg(args, char *);
	int j = 0;

(void)width;
(void)precision;
(void)size;
(void)flags;

if (str == NULL)
	str = "(null)";
while (str[j])
{
buff[i] = str[j];
j++;
i++;
}
return (j);
}

/*************************Print Percent*************************/
/**
* print_percent - prints a percent symbol
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_percent(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
(void)args;
(void)width;
(void)precision;
(void)size;
(void)flags;

buff[i] = '%';
return (1);
}

/*************************Print Int*************************/
/**
* print_int - print integer
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_int(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
int j = BUFF_SIZE - 2;
int is_negative = 0;
long int num = va_arg(args, int);
unsigned long int num2;
num2 = convert(num, 10, 0, flags);

(void)width;	
(void)precision;
(void)size;

if (num < 0)
{
is_negative = 1;
num2 = -num;
}
if (num == 0)
{
buff[j] = '0';
return (1);
}
while (num2 != 0)
{
buff[j] = (num2 % 10) + '0';
num2 /= 10;
j--;
}
if (is_negative)
{
buff[j] = '-';
return (1);
}
return (BUFF_SIZE - 1 - j);
}

/*************************Print Binary*************************/
/**
* print_binary - print an unsigned number
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_binary(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
unsigned int j = BUFF_SIZE - 2;
unsigned int num = va_arg(args, unsigned int);
unsigned int num2;	
num2 = convert(num, 2, 0, flags);

(void)width;
(void)precision;
(void)size;

if (num == 0)
{
buff[j] = '0';
return (1);
}
while (num2 != 0)
{
buff[j] = (num2 % 10) + '0';
num2 /= 10;
j--;
}
return (BUFF_SIZE - 1 - j);
}

/*************************Print Unsigned Int*************************/
/**
* print_unsigned - print an unsigned number
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_unsigned(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
unsigned int j = BUFF_SIZE - 2;
unsigned int num = va_arg(args, unsigned int);
unsigned int num2;
num2 = convert(num, 10, 0, flags);

(void)width;
(void)precision;
(void)size;

if (num == 0)
{
buff[j] = '0';
return (1);
}
while (num2 != 0)
{
buff[j] = (num2 % 10) + '0';
num2 /= 10;
j--;
}
return (BUFF_SIZE - 1 - j);
}

/*************************Print Octal*************************/
/**
* print_octal - print an unsigned number in octal notation
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_octal(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
	unsigned int j = BUFF_SIZE - 2;
unsigned int num = va_arg(args, unsigned int);
unsigned int num2;
num2 = convert(num, 8, 0, flags);

(void)width;
(void)precision;
(void)size;

if (num == 0)
{
buff[j] = '0';
return (1);
}
while (num2 != 0)
{
buff[j] = (num2 % 10) + '0';
num2 /= 10;
j--;
}
return (BUFF_SIZE - 1 - j);
}

/*************************Print Hex*************************/
/**
* print_hex - print an unsigned number in hexadecimal notation
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_hex(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
unsigned int j = BUFF_SIZE - 2;
unsigned int num = va_arg(args, unsigned int);
unsigned int num2;
num2 = convert(num, 16, 0, flags);

(void)width;
(void)precision;
(void)size;

if (num == 0)
{
buff[j] = '0';
return (1);
}
while (num2 != 0)
{
if (num2 % 16 < 10)
buff[j] = (num2 % 16) + '0';
else
buff[j] = (num2 % 16) + 'W';
num2 /= 16;
j--;
}
return (BUFF_SIZE - 1 - j);
}

/*************************Print Hex Upper*************************/
/**
* print_hex_upper - print an unsigned number in upper hexadecimal notation
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_hex_upper(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
unsigned int j = BUFF_SIZE - 2;
unsigned int num = va_arg(args, unsigned int);
unsigned int num2;
num2 = convert(num, 16, 1, flags);

(void)width;
(void)precision;
(void)size;

if (num == 0)
{
buff[j] = '0';
return (1);
}
while (num2 != 0)
{
if (num2 % 16 < 10)
buff[j] = (num2 % 16) + '0';
else
buff[j] = (num2 % 16) + '7';
num2 /= 16;
j--;
}
return (BUFF_SIZE - 1 - j);
}

/*************************Convert*************************/
/**
* convert - convert a number to another base
* @num: number to convert
* @base: base to convert to
* @is_upper: flag to determine if hex is upper or lower case
* @flags: flags to determine if number is signed or not
* Return: converted number
*/

unsigned long int convert(unsigned long int num, int base, int is_upper, int flags)
{
	unsigned long int num2 = 0;
	int i = 1;
	int rem;

	if (flags & F_LONG)
	{
		while (num != 0)
		{
			rem = num % base;
			num /= base;
			if (rem < 10)
				rem += '0';
			else
				rem += is_upper ? '7' : 'W';
			num2 += rem * i;
			i *= 10;
		}
	}
	else
	{
		while (num != 0)
		{
			rem = num % base;
			num /= base;
			if (rem < 10)
				rem += '0';
			else
				rem += is_upper ? '7' : 'W';
			num2 += rem * i;
			i *= 10;
		}
	}
	return (num2);
}

/*************************Print Non Printable*************************/
/**
* print_non_printable - print a non printable character
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_non_printable(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
	char *str = va_arg(args, char *);
	int j = 0;
	char *hex = "0123456789ABCDEF";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(null)";
	while (str[j])
	{
		if (str[j] < 32 || str[j] >= 127)
		{
			buff[i] = '\\';
			i++;
			buff[i] = 'x';
			i++;
			buff[i] = hex[(str[j] / 16) % 16];
			i++;
			buff[i] = hex[str[j] % 16];
			i++;
		}
		else
		{
			buff[i] = str[j];
			i++;
		}
		j++;
	}
return (j);
}

/*************************Print Pointer*************************/
/**
* print_pointer - print a memory address
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_pointer(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int num2;
	unsigned int j = BUFF_SIZE - 2;
	char *hex = "0123456789abcdef";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (num == 0)
	{
		buff[j] = '(';
		j--;
		buff[j] = 'n';
		j--;
		buff[j] = 'i';
		j--;
		buff[j] = 'l';
		j--;
		buff[j] = ')';
		j--;
		return (6);
	}
	buff[j] = 'x';
	j--;
	buff[j] = '0';
	j--;
	while (num != 0)
	{
		num2 = num % 16;
		buff[j] = hex[num2];
		num /= 16;
		j--;
	}
	return (BUFF_SIZE - 1 - j);
}

/*************************Print Reverse*************************/
/**
* print_reverse - print a string in reverse
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/

int print_rev_string(va_list types, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
char *str = va_arg(types, char *);
	int j = 0;
	int k = 0;

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(null)";
	while (str[j])
		j++;
	j--;
	while (j >= 0)
	{
		buff[i] = str[j];
		i++;
		j--;
		k++;
	}
	return (k);
}

int print_reverse(va_list args, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
	char *str = va_arg(args, char *);
	int j = 0;
	int k = 0;

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(null)";
	while (str[j])
		j++;
	j--;
	while (j >= 0)
	{
		buff[i] = str[j];
		i++;
		j--;
		k++;
	}
	return (k);
}

/*************************Print Rota13*************************/
/**
* print_rot13 - print a string in rot13
* @type: list of arguments
* buffer: buffer array to handle print
* @flags: Calcutate active flags
* width: width
* precision: precision specification
* size: size specification
* Return: number of characters printed
*/
int print_rot13sting(va_list types, char* buff, unsigned int i, int flags, int width, int precision, int size)
{
	char *str = va_arg(types, char *);
	int j = 0;
	int k = 0;
	char *alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(null)";
	while (str[j])
	{
		k = 0;
		while (alpha[k])
		{
			if (str[j] == alpha[k])
			{
				buff[i] = rot13[k];
				i++;
				break;
			}
			k++;
		}
		if (!alpha[k])
		{
			buff[i] = str[j];
			i++;
		}
		j++;
	}
	return (j);
}
	return 0;
}