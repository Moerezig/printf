#include "main.h"


/**
* _printf - a custom printf function
* @format: the format string
* Return: number of characters printed
*/

int _printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    specifier sp[] = {
        {"%s", print_string},
        {"%c", print_char},
        {"%%", print_percent}
    };

    char buffer[256];
    int total_chars_written = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            int j;
            for (j = 0; j < sizeof(sp) / sizeof(specifier); j++) {
                if (format[i + 1] == sp[j].spec[1]) {
                    int chars_written = sp[j].func(args, buffer);
                    total_chars_written += chars_written;
                    i++;
                    break;
                }
            }
            if (j == sizeof(sp) / sizeof(specifier)) {
                buffer[0] = format[i];
                buffer[1] = '\0';
                write(1, buffer, 1);
                total_chars_written++;
            }
        } else {
            buffer[0] = format[i];
            buffer[1] = '\0';
            write(1, buffer, 1);
            total_chars_written++;
        }
    }

    va_end(args);

    return total_chars_written;
}
