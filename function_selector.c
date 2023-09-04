#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int select(char c , va_list args)
{
    if (c == 'c')
    {
        return printf_char(args);;
    }
    else if (c == 's')
    {
        return printf_string(args);
    }
    else if (c == '%')
    {
        return printf_percent();
    }
    else
    {
        putchar('%');
        putchar(c);
        return (2);
    }
}

