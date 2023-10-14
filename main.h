#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    const char* spec;
    int (*func)(va_list, char*);
} specifier;

int print_string(va_list args, char* buffer);
int print_char(va_list args, char* buffer);
int print_percent(va_list args, char* buffer);
int _printf(const char* format, ...);

#endif
