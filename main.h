#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void append_to_buffer(char *buffer, char c, int *index);
int _printf(const char *format, ...);

#endif /* MAIN_H */

