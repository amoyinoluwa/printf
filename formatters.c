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
	int k, j, count, val, zeros;

	val = va_arg(arg, int);

	count = 0;
	zeros = 1;

	if (val < 0)
	{
		_putchar('-');
		val *= -1;
		count++;
	}

	k = j = val;

	while (val > 10)
	{
		val /= 10;
		zeros *= 10;
	}

	_putchar(k / zeros + '0');
	count += 1;

	while(j > 10)
	{
		zeros /= 10;
		_putchar((k / zeros) % 10 + '0');
		count += 1;
		j /= 10;
	}

	return (count);
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
	int zeros = 1;
	int k, j;

	val = va_arg(arg, unsigned int);
	k = j = val;

	while (val > 10)
	{
		val /= 10;
		zeros *= 10;
	}
	_putchar(k / zeros + '0');
	count += 1;

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
