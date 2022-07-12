#include "main.h"

/**
 * get_formatter - gets the correct function for formatting
 * @format: format specified by user
 * Return: correct formatter
 */

int (*get_formatter(char format))(va_list)
{
	int i;

	formatter form[] = {
		{'c', format_char},
		{'s', format_string},
		{'d', format_number},
		{'i', format_number},
		{'b', format_binary}
	};

	i = 0;

	while (i < 5)
	{
		if (form[i].f == format)
		{
			return (form[i].func);
		}
		i++;
	}
	return (NULL);
}
