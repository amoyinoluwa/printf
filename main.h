#ifndef MAIN_H
#define MAIN_H

/**
 * struct formatters - defines a struct for formatting
 * @f: format specified
 * @func: chooses the right function for formatting
 */

typedef struct formatters
{
	char *f;
	int (*func)(va_list);
} formatter;

int format_string(va_list args);
int format_number(va_list args);
int _putchar(char c);

#endif
