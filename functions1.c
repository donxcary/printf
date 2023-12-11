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

int print_string(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	char* str = va_arg(type, char*);
	int i = 0;

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	return (i);
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

int print_percent(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	(void)type;
	(void)precision;
	(void)size;
	(void)flags;

	buffer[0] = '%';
	(void)width;
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

int print_int(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int num = va_arg(type, int);
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
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		buffer[i] = (num2 % 10) + '0';
		num2 /= 10;
		i--;
	}
	if (is_negative)
	{
		buffer[i] = '-';
		return (1);
	}
	return (BUFF_SIZE - 1 - i);
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

int print_binary(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(type, unsigned int);
	unsigned int num2;
	num2 = convert(num, 2, 0, flags);

	(void)width;
	(void)precision;
	(void)size;

	if (num == 0)
	{
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		buffer[i] = (num2 % 10) + '0';
		num2 /= 10;
		i--;
	}
	return (BUFF_SIZE - 1 - i);
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

int print_unsigned(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(type, unsigned int);
	unsigned int num2;
	num2 = convert(num, 10, 0, flags);

	(void)width;
	(void)precision;
	(void)size;

	if (num == 0)
	{
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		buffer[i] = (num2 % 10) + '0';
		num2 /= 10;
		i--;
	}
	return (BUFF_SIZE - 1 - i);
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

int print_octal(va_list type, char* buffer, int* flags, int width, int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(type, unsigned int);
	unsigned int num2;
	num2 = convert(num, 8, 0, flags);

	(void)width;
	(void)precision;
	(void)size;

	if (num == 0)
	{
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		buffer[i] = (num2 % 10) + '0';
		num2 /= 10;
		i--;
	}
	return (BUFF_SIZE - 1 - i);
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

int print_hex(va_list type, char* buffer, int* flags, int width, int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(type, unsigned int);
	unsigned int num2;
	num2 = convert(num, 16, 0, flags);

	(void)width;
	(void)precision;
	(void)size;

	if (num == 0)
	{
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		if (num2 % 16 < 10)
			buffer[i] = (num2 % 16) + '0';
		else
			buffer[i] = (num2 % 16) + 'W';
		num2 /= 16;
		i--;
	}
	return (BUFF_SIZE - 1 - i);
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

int print_hex_upper(va_list type, char* buffer, int* flags, int width, int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(type, unsigned int);
	unsigned int num2;
	num2 = convert(num, 16, 1, flags);

	(void)width;
	(void)precision;
	(void)size;

	if (num == 0)
	{
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		if (num2 % 16 < 10)
			buffer[i] = (num2 % 16) + '0';
		else
			buffer[i] = (num2 % 16) + '7';
		num2 /= 16;
		i--;
	}
	return (BUFF_SIZE - 1 - i);
}

/*************************Print Hex Lower or Upper*************************/
/**
* print_hex - print hexadecimal number in lower or upper case
* @type: list of arguments
* @map_to : array of values to map the number to
* buffer : buffer array to handle print
* @flags : Calcutate active flags
* @flag_ch: calculate active flags
* width : get width
* precision : precision specification
* size : size specification
* Return : number of characters printed
*/
int print_hex(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	unsigned int i = BUFF_SIZE - 2;
	unsigned int num = va_arg(type, unsigned int);
	unsigned int num2;
	char* map_to = "0123456789abcdef";
	int flag_ch = flags[3];

	num2 = convert(num, 16, flag_ch, flags);
	(void)width;
	(void)precision;
	(void)size;

	if (num == 0)
	{
		buffer[i] = '0';
		return (1);
	}
	while (num2 != 0)
	{
		buffer[i] = map_to[num2 % 16];
		num2 /= 16;
		i--;
	}
	return (BUFF_SIZE - 1 - i);
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
int print_reverse(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	char* str = va_arg(type, char*);
	int i = 0, j = 0;

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = ")llun(";
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		buffer[j] = str[i];
		i--;
		j++;
	}
	return (j);
}

/*************************Print Rot13*************************/
/**
 * print_rot13string - print a string in rot13
 * @type: list of arguments
 * @buffer: buffer array to handle print
 * @flags: Calcutate active flags
 * @width: width
 * @precision: precision specification
 * @size: size specification
 * Return: number of characters printed
 */
int print_rot13string(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	char* str = va_arg(type, char*);
	int i = 0, j = 0;
	char* rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(ahyy)";
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') ||
			(str[i] >= 'a' && str[i] <= 'z'))
		{
			j = 0;
			while (str[i] != rot13[j])
				j++;
			buffer[i] = rot13[j + 13];
		}
		else
			buffer[i] = str[i];
		i++;
	}
	return (i);
}

/*************************Print Pointer*************************/
/**
 * print_pointer - print the value of a pointer variable
 * @type: list of arguments
 * @buffer: buffer array to handle print
 * @flags: Calcutate active flags
 * @width: width
 * @precision: precision specification
 * @size: size specification
 * Return: number of characters printed
 */
int print_pointer(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int num2;
	int i = BUFF_SIZE - 2;
	char* map_to = "0123456789abcdef";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (num == 0)
	{
		buffer[i] = '(';
		buffer[i - 1] = 'n';
		buffer[i - 2] = 'o';
		buffer[i - 3] = 'l';
		buffer[i - 4] = 'l';
		buffer[i - 5] = 'u';
		buffer[i - 6] = 'n';
		buffer[i - 7] = ')';
		return (8);
	}
	while (num != 0)
	{
		num2 = num % 16;
		buffer[i] = map_to[num2];
		num /= 16;
		i--;
	}
	buffer[i] = 'x';
	buffer[i - 1] = '0';
	return (BUFF_SIZE - 1 - i);
}

/*************************Print Non Printable*************************/
/**
 * print_non_printable - print ascii code in hex of non printable characters
 * @type: list of arguments
 * @buffer: buffer array to handle print
 * @flags: Calcutate active flags
 * @width: width
 * @precision: precision specification
 * @size: size specification
 * Return: number of characters printed
 */

int print_non_printable(va_list type, char* buffer, int* flags, int width,
	int precision, int size)
{
	char* str = va_arg(type, char*);
	int i = 0, j = 0;
	char* hex = "0123456789abcdef";

	(void)width;
	(void)precision;
	(void)size;
	(void)flags;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			buffer[j] = '\\';
			buffer[j + 1] = 'x';
			buffer[j + 2] = hex[str[i] / 16];
			buffer[j + 3] = hex[str[i] % 16];
			j += 4;
		}
		else
		{
			buffer[j] = str[i];
			j++;
		}
		i++;
	}
	return (j);
}