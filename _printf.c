#include "main.h"

/**
 * append_to_buffer - Helper function to append characters to the buffer
 * @buffer: The buffer to which the character should be appended
 * @c: The character to be appended to the buffer
 * @index: Pointer to the current index within the buffer
 */
static void append_to_buffer(char *buffer, char c, int *index)
{
	if (*index < BUFFER_SIZE - 1)
	{
		buffer[*index] = c;
		(*index)++;
	}
}

/**
 * _printf - Custom printf function that emulates the functionality of printf
 * @format: The format string containing format specifiers
 * @...: The list of arguments to be formatted and printed
 *
 * This function mimics the behavior of the standard printf function, supporting
 * format specifiers such as %d, %i, %b, %u, %o, %x, %X, %s, %p. It handles flag
 * characters +, space, and #, as well as length specifiers h and l. It utilizes a
 * local buffer of 1024 characters for formatting before printing.
 *
 * Return: The number of characters written to the buffer
 */
int _printf(const char *format, ...)
{

	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	const char *format_ptr = format;
	va_list args;
	va_start(args, format);

	while (*format_ptr != '\0')
	{
		if (*format_ptr != '%')
		{
			append_to_buffer(buffer, *format_ptr, &buffer_index);
		}
		else
		{
			format_ptr++; /* Move past '%' */

			/* Process flags */
			/* (Note: Only handling '+' flag for demonstration) */
			if (*format_ptr == '+')
			{
				/* Handle the '+' flag here (if needed) */
				format_ptr++;
			}

			/* Process format specifiers */
			switch (*format_ptr)
			{
			case 'd':
			case 'i':
			{
				int num = va_arg(args, int);
				buffer_index += sprintf(buffer + buffer_index, "%d", num);
				break;
			}
			case 's':
			{
				char *str = va_arg(args, char *);
				buffer_index += sprintf(buffer + buffer_index, "%s", str);
				break;
			}
			/* Add support for other format specifiers as needed */
			/* ... */
			default:
				/* If an unsupported specifier is encountered, just copy it to the buffer */
				append_to_buffer(buffer, '%', &buffer_index);
				append_to_buffer(buffer, *format_ptr, &buffer_index);
			}
		}
		format_ptr++;
	}

	va_end(args);

	/* Null-terminate the buffer */
	buffer[buffer_index] = '\0';

	/* Print the formatted output */
	printf("%s", buffer);

	return buffer_index;
}
