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

int format_char(va_list arg)
{
	return (_putchar(va_arg(arg, int)));
}

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
