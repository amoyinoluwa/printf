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
	return (_putchar(va_arg(arg, int)));
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

	_putchar(k/zeros + '0');
	count += 1;

	while(j > 10)
	{
		zeros /= 10;
		_putchar((k/zeros) % 10 + '0');
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
	unsigned int num;
	int len = 0;
	int d = 1;

	num = va_arg(list, unsigned int);
	for (; num / d > 9; )
	{
		d = d * 10;
	}
	while (d > 0)
	{
		len += _putchar('0' + (num / d));
		num = num % d;
		d = d / 10;
	}
	return (len);
}
