#ifndef MAIN_H
#define MAIN_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdarg.h>

typedef struct specifier
{
    char *v;
    void (*fun)(va_list);
} spec;

int _printf(const char *format, ...);
int print_c(va_list list);
int print_s(va_list list);
int print_percent(va_list list);
int _putchar(char c);

#endif
