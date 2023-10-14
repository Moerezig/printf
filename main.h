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
int _print(int j);
int handle_char(va_list list, int count);
int handle_string(va_list list, int count);
int handle_int(va_list list, int count);


#endif
