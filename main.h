#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * struct format - match the specifiers
 * @spec: pointer of the format specifier
 * @func: pointer to the function
 */
typedef struct format 
{
	char *spec;
	int (*func)(va_list, char[]);
} specifiers;

int _printf(const char *format, ...);
int print_string(va_list list, char buffer[]);
int print_char(va_list list, char buffer[]);
int print_percent(va_list list, char buffer[]);
void buffer_putchar(char c, char buffer[], int *buffer_index, int *chars_printed);
void buffer_flush(char buffer[], int *buffer_index);
#endif
