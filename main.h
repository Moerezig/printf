#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int print_number(int n);
int print_unsigned_number(unsigned int n);
int print_binary(unsigned int n);
int print_rot13_string(const char *str);
int print_reversed_string(const char *str);

#endif
