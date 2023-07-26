#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom implementation of the printf function for formatted output.
 *
 * This function takes a format string and a variable number of arguments, and
 * it produces formatted output to the standard output (file descriptor 1).
 * The format string may contain conversion specifiers starting with '%', which
 * are replaced by the corresponding argument values. The supported conversion
 * specifiers are 'c' for characters, 's' for strings, '%' for a literal '%',
 * 'd' and 'i' for signed integers, 'u' for unsigned integers (decimal), 'o'
 * for unsigned integers (octal), 'x' for unsigned integers (lowercase
 * hexadecimal), 'X' for unsigned integers (uppercase hexadecimal), and 'b' for
 * unsigned integers (binary).
 *
 * @format: The format string specifying the output format.
 * Return: The number of characters written to the standard output.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int char_count = 0;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			char_count += select(*format, args);
		}
		else
		{
			putchar(*format);
			char_count++;
		}
		format++;
	}
	va_end(args);
	return (char_count);
}
