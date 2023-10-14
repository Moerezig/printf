#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // Counter to keep track of the number of characters printed

    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move to the next character after '%'

            // Check the conversion specifier
            switch (*format) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char*);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%':
                    putchar('%');
                    count++;
                    break;
            }
        } else {
            putchar(*format);
            count++;
        }
        format++; // Move to the next character in the format string
    }

    va_end(args);
    return count;
}
