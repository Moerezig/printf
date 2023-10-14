#include "main.h"



/**
* print_string - print a string
* @args: list of arguments
* @buffer: buffer array to handle
* Return: 0 on success
*/


int print_string(va_list args, char* buffer) {
    char* str = va_arg(args, char*);
    int chars_written = sprintf(buffer, "%s", str);
    write(1, buffer, chars_written);
    return chars_written;
}

/**
* print_char - print a character
* @args: list of arguments
* @buffer: buffer array to handle print
* Return: 0 on success
*/

int print_char(va_list args, char* buffer) {
    char c = va_arg(args, int);
    int chars_written = sprintf(buffer, "%c", c);
    write(1, buffer, chars_written);
    return chars_written;
}

/**
* print_percent - print a percentage
* @args: list of args
* @buffer: buffer to print
* Return: 0 to indicate success
*/

int print_percent(va_list args, char* buffer) {
    int chars_written = sprintf(buffer, "%%");
    write(1, buffer, chars_written);
    return chars_written;
}
