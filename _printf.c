#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

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
	int i, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed_chars += handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (printed_chars == -1)
			{
				va_end(args);
				return (-1);
			}
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
