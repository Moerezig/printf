#include "main.h"
#include <stdio.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * printf - a custom printf function
 * @format: print char
 * Return: the formatted string
*/
int _printf(const char *format, ...) {
  va_list args;
  int buffer_index = 0;
  char buffer[BUFFER_SIZE];

  if (format == NULL) {
    return (-1);
  }

  va_start(args, format);

  while (format) {
    if (*format != '%') {
      buffer[buffer_index++] = *format;
    } else {
      format++;

      switch (*format) {
        case 'c':
          buffer[buffer_index++] = va_arg(args, int);
          break;
        case 's':
          char *str = va_arg(args, char *);
          int str_len = 0;
          while (*str != '\0') {
            str_len++;
            str++;
          }
          memcpy(&buffer[buffer_index], str, str_len);
          buffer_index += str_len;
          break;
        default:
        // handle other here
          break;
      }
    }

    format++;
  }

  va_end(args);

  buffer[buffer_index] = '\0';
  write(1, buffer, buffer_index);

  return (buffer_index);
}


