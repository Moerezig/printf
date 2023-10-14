#include "main.h"

/**
* print_char - print a character
* @list: list of arguments
* @buffer: buffer array to handle print
* Return: 0 on success
*/

int print_char(va_list list, char buffer[])
{
    int* buffer_index;
    char c;
    c = va_arg(list, int); //get the char arg from the va_list
    buffer_putchar(c, buffer, &buffer_index); //store the char
    return (0);
}


/**
* print_string - print a string
* @list: list of arguments
* @buffer: buffer array to handle
* Return: 0 on success
*/

int print_string(va_list list, char buffer[])
{
    int* buffer_index;
    char *str = va_arg(list, char*); // Get the string argument from va_list
    int i = 0;

    while (str[i] != '\0')
    {
        buffer_putchar(str[i], buffer, &buffer_index); // Store each character of the string in the buffer
        i++;
    }

    return 0; // Return 0 to indicate success
}

/**
* print_percent - print a percentage
* @list: list of args
* @buffer: buffer to print
* Return: 0 to indicate success
*/

int print_percent(va_list list, char buffer[])
{
    buffer_putchar('%', buffer, &buffer_index); // Store the percent character in the buffer
    return 0; // Return 0 to indicate success
}
