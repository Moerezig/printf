#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - a custom printf function
* @format: the format string
* Return: number of characters printed
*/

int _printf(const char *format, ...)
{
	specifiers sp[] =
	{
		{"%s", print_string},
		{"%c", print_char},
		{"%%", print_percent}
	};

	int i, j = 0;
	va_list list;
	char buffer[BUFFER_SIZE];
	int buffer_index = 0;
	int chars_printed = 0;

	if (format == NULL || format[0] == '\0')
	return (-1);

	va_start(list, format);

	while (format[j] != '\0')
	{
	if (format[j] == '%')
	{
		j++;
		for (i = 0; i < 3; i++)
	{
		if (format[j] == *(sp[i].spec))
		{
			sp[i].func(list, buffer, &chars_printed);
			break;
		}
	}
	if (i == 3)
	{
		buffer_putchar('%', buffer, &buffer_index);
		buffer_putchar(format[j], buffer, &buffer_index);
		chars_printed += 2;
	}
		j++;
	}
	else
	{
		buffer_putchar(format[j], buffer, &buffer_index);
		chars_printed++;
		j++;
	}
	}

	buffer_flush(buffer, &buffer_index);
	va_end(list);

	return (chars_printed);
}
