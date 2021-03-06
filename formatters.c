#include "main.h"

/**
 * _putchar - prints character to terminal
 * @c: char argument
 * Return: character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * format_char - prints char type arg to stdout
 * @arg: char arg
 * Return: char
 */

int format_char(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * format_string - print char* type arg to stdout
 * @arg: str arg
 * Return: count of printed items
 */

int format_string(va_list arg)
{
	char *str;
	int i;

	str = va_arg(arg, char*);

	if (str == NULL)
		str = "(null)";
	i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

/**
 * format_number - formats int input for printf
 * @arg: int argument
 * Return: number of args printed
 */

int format_number(va_list arg)
{
	unsigned int divisor = 1, i, resp, charPrinted = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		charPrinted++;
		n *= -1;
	}
	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;
	for (; divisor >= 1; n %= divisor, divisor /= 10, charPrinted++)
	{
		resp = n / divisor;
		_putchar('0' + resp);
	}

	return (charPrinted);
}

/**
 * format_unsigned - prints unsigned int to stdout
 * @arg: va list argument
 * Return: unsigned int
 */

int format_unsigned(va_list arg)
{
	unsigned int val;
	int count = 0;
	unsigned int zeros = 1;
	unsigned int k, j, res;

	val = va_arg(arg, unsigned int);
	k = j = val;

	while (val > 10)
	{
		val /= 10;
		zeros *= 10;
	}
	res = k / zeros;
	if (res < 10)
	{
		_putchar(res + '0');
		count += 1;
	}
	else
	{
		_putchar(res / 10 + '0');
		_putchar(res % 10 + '0');
		count += 2;
	}

	while (j > 10)
	{
		zeros /= 10;
		_putchar((k / zeros) % 10 + '0');
		count += 1;
		j /= 10;
	}
	return (count);
}

/**
 * format_binary - function to convert decimal to binary
 * @arg: unsigned int arg
 * Return: number of characters printed
 */

int format_binary(va_list arg)
{
	unsigned int val;
	int binary[64];
	int i = 0, j, count = 0;

	val = va_arg(arg, unsigned int);

	if (val == 0)
	{
		_putchar('0');
		return (1);
	}
	while (val)
	{
		binary[i++] = val % 2;
		val /= 2;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(binary[j] + '0');
		count++;
	}
	return (count);
}

/**
 * format_octal - formats decimal input to octal
 * @arg: list of args
 * Return: octal representation of arg
 */

int format_octal(va_list arg)
{
	unsigned int val;
	int octal[64];
	int i = 0, j, count = 0;

	val = va_arg(arg, unsigned int);
	if (val == 0)
	{
		_putchar('0');
		return (1);
	}
	while (val)
	{
		octal[i++] = val % 8;
		val /= 8;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(octal[j] + '0');
		count++;
	}
	return (count);
}

/**
 * format_hex - converts integer to small hex
 * @arg: argument list
 * Return: small hex
 */

int format_hex(va_list arg)
{
	unsigned int val;
	int hex[64];
	int i = 0, j, count = 0, rem;

	val = va_arg(arg, unsigned int);
	if (val == 0)
	{
		_putchar('0');
		return (1);
	}
	while (val)
	{
		rem = val % 16;
		if (rem > 9 && rem < 16)
		{
			rem += 39;
		}
		hex[i++] = rem;
		val /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(hex[j] + '0');
		count++;
	}
	return (count);
}

/**
 * format_HEX - converts integer to big hex
 * @arg: argument list
 * Return: big hex
 */

int format_HEX(va_list arg)
{
	unsigned int val;
	int hex[64];
	int i = 0, j, count = 0, rem;

	val = va_arg(arg, unsigned int);
	if (val == 0)
	{
		_putchar('0');
		return (1);
	}
	while (val)
	{
		rem = val % 16;
		if (rem > 9 && rem < 16)
		{
			rem += 7;
		}
		hex[i++] = rem;
		val /= 16;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(hex[j] + '0');
		count++;
	}
	return (count);
}
