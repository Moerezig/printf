#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    
    int count = 0; // Counter for the number of characters printed
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past the '%'
            
            // Check the next character after '%'
            switch (*format) {
                case 'c': {
                    // Print a single character
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    // Print a string
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    // Print a percent sign
                    putchar('%');
                    count++;
                    break;
                }
                default: {
                    // Invalid conversion specifier, ignore it
                    break;
                }
            }
        } else {
            // Regular character, print it
            putchar(*format);
            count++;
        }
        
        format++; // Move to the next character in the format string
    }
    
    va_end(args);
    
    return count;
}
