#include "main.h"

/**
 * get_formatter - gets the correct function for formatting
 * @format: format specified by user
 * Return: correct formatter
 */

int (*get_formatter(char *format))(va_list)
{
	int i;

	formatter f[] = {
		{"c", print_char},
		{"s", format_string},
		{"d", format_number},
		{"i", format_unsigned}
	};

	i = 0;

	while (i < 4)
	{
		if (f[i].f == format)
		{
			return (f[i].func);
		}
		i++;
	}
	return (NULL);
}
