#ifndef MAIN_H
#define MAIN_H

/*** HEADER FILES ****/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits>


/*** STRUCT FORMAT ***/

typedef struct format
{
    char *home;
    int (*f)();
} Specifiers;

/*** PROTOTYPE FUNCTIONS ***/

/*** TASK 0 ***/
int _printf(const char *format, ...);
int _putchar(char c);
int printf_char(va_list val);

/*** TASK 1  */

int printf_deceimal(va_list args);
int printf_int(va_list args);

/*** TASK 2  */

/*** TASK 3  */

/*** TASK 4  */

/*** TASK 5  */

/*** TASK 6  */

/*** TASK 7  */

/*** TASK 8  */

/*** TASK 9  */

/*** TASK 10 */

/*** TASK 11 */

/*** TASK 12 */

/*** TASK 13 */

/*** TASK 14 */

#endif