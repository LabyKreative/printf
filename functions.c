#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - a function that prints a character.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: characters printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - a function that prints a string.
 * @types: list a of arguments.
 * @buffer: buffer array to handle print.
 * @flags:  calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: strings number printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, x;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (x = width - length; x > 0; x--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (x = width - length; i > 0; x--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - a function that prints a percent sign.
 * @types: lista of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: printed chars number.
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - a function that prints int.
 * @types: list of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: printed number of chars.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - a function that prints an unsigned number.
 * @types: lista of arguments.
 * @buffer: buffer array to handle print.
 * @flags: calculates active flags.
 * @width: get width.
 * @precision: precision specification.
 * @size: size specifier.
 * Return: printed char numbers.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int y, w, x, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	y = va_arg(types, unsigned int);
	w = 2147483648; /* (2 ^ 31) */
	a[0] = y / w;
	for (x = 1; x < 32; x++)
	{
		w /= 2;
		a[x] = (y / w) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
			char z = '0' + a[x];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
