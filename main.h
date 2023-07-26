#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

#define BUFF_SIZE 1024

/**
 * struct convert_match - Struct to match conversion specifier with function
 * @id: The conversion specifier (e.g., "%s")
 * @f: The corresponding function
 */
typedef struct convert_match
{
	char *id;
	int (*f)(va_list);
} convert_match;

/* Function prototypes */
int _putchar(char c);
int _printf(const char *format, ...);
int printf_char(va_list args);
int printf_string(va_list args);
int printf_int(va_list args);
int printf_unsigned(va_list args);
int printf_oct(va_list args);
int printf_hex(va_list args);
int printf_HEX(va_list args);
int printf_pointer(va_list args);
void print_buffer(char buffer[], int *buff_ind);
int handle_print(const char *format, int *i, va_list args,
		 char buffer[], int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
int _putchar(char c);
int _printf(const char *format, ...);

#endif /* MAIN_H */

