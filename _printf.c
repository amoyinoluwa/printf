#include "main.h"

/**
 * _printf - prints user input to terminal
 * @format: string arg
 * Return: formatted string
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int i, count;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	i = count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
				count++;
			}
			else
			{
				f = get_formatter(format[i + 1]);
				if (f == NULL)
				{
					_putchar('%');
					_putchar(format[i + 1]);
					count += 2;
				}
				else
				{
					count += f(arg);
				}
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(arg);
	return (count);
}
