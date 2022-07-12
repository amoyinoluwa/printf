#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct formatters - defines a struct for formatting
 * @f: format specified
 * @func: chooses the right function for formatting
 */

typedef struct formatters
{
	char f;
	int (*func)(va_list);
} formatter;

int _printf(const char *format, ...);
int format_string(va_list);
int format_number(va_list);
int format_char(va_list);
int format_unsigned(va_list);
int format_binary(va_list);
int format_octal(va_list);
int format_hex(va_list);
int format_HEX(va_list);
int _putchar(char c);
int (*get_formatter(char format))(va_list);

#endif
