#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * printf - a custom printf function
 * @format: print char
 * Return: the formatted string
*/
	int _printf(const char *format, ...) 
{
	*format [BUFFER_SIZE]
	int buffer_index = 0
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, *format);

	switch(*format)
	{
		case *format != '%'
		write (1, *format, 1);
		break;
		default:
		format++;
		break;
	}
	while(*format) {
		if (*format == '\0')
		break;
			else if (*format == '%')
			{
				write(1, format, 1)
				buffer_index++;
			}
		else if (*format == 'c')
		{
		char c = va_arg(args, int);
		write(1, &c, 1)
		buffer_index+1;
		}	
		else if (*format == 's')
		{
		char *str = va_arg(args. char*);
		int str_len = buffer_index
			while(str[str_len] != '\0')
			str_len++;
			write(1, str, str_len)
			buffer_index += str_len
		}
	format+1;
	}
	va_end(args)

	return buffer_index;
}
