#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * printf_char - Handle the 'c' conversion specifier for _printf.
 * @ap: The character to be printed.
 * Return: The updated character count after printing the character.
 */
int printf_char(va_list ap)
{
	int count = 0;
	char c = va_arg(ap, int);

	putchar(c);
	count++;
	return (count);
}

/**
 * printf_string - Handle the 's' conversion specifier for _printf.
 * @ap: The string to be printed.
 * count: The current character count.
 * Return: The updated character count after printing the string.
 */
int printf_string(va_list ap)
{
	int count = 0;
	char *s = va_arg(ap, char *);

	if (s == NULL)
	{
		fputs("(null)", stdout);
		return (6);
	}

	while (*s != '\0')
	{
		putchar(*s);
		count++;
		s++;
	}
	return (count);
}

/**
 * printf_percent - Handle the '%%' conversion specifier for _printf.
 * Return: The updated character count after printing the '%'.
 */
int printf_percent(void)
{
	int count = 0;

	putchar('%');
	count++;
	return (count);
}

/**
 * printf_literal_percent - Print a literal '%' for unrecognized conversion %
 * @format: The format string (character pointer).
 * Return: The number of characters written (2 for the literal '%' and the
 *         character following '%').
 */
int printf_literal_percent(const char *format)
{
	int count = 0;

	while (*format == '%')
	{
		putchar('%');
		format++;
		count++;
	}
	putchar(*format);
	count++;
	return (count);
}
