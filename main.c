#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    int num1, num2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);

    num1 = _printf("A %s sentence\n", "simple");
    num2 = printf("A %s sentence\n", "simple");
    printf("Len:[%d]\n", num1);
    printf("Len1:[%d]\n\n", num2);
    
    num1 = _printf("A %c%c%s sentence\n", 's', 'i', "mple");
    num2 = printf("A %c%c%s sentence\n", 's', 'i', "mple");
    printf("Len:[%d]\n", num1);
    printf("Len1:[%d]\n\n", num2);

    num1 = _printf("A simple %v entence\n");
    num2 = printf("A simple %v entence\n");
    printf("Len:[%d]\n", num1);
    printf("Len1:[%d]\n\n", num2);

    num1 = _printf("Percentage: %%\n");
    num2 = printf("Percentage: %%\n");
    printf("Len:[%d]\n", num1);
    printf("Len1:[%d]\n\n", num2);

    num1 = _printf("Hello %\n");
    num2 = printf("Hello %\n");

    printf("%d || %d\n", num1,num2);
    _printf("Hello %  \n");
    printf("Hello %  \n");
    printf("%d || %d\n", num1,num2);

    len = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	len2 = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
    
    num1 = _printf("%%");
    num2 = printf("%%");

    num1 = _printf("%c",'\0');
    num2 = _printf("%");
    num1 = _printf("%!\n");
    num2 = _printf(NULL);
    num1 = _printf("%s",NULL);

    return (0);
}