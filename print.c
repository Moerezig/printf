#include "main.h"
#include <stdio.h>
#include <stdarg.h>


// int _printf(const char *format, ...);
//
// Returns: the number of characters printed (excluding the null byte used to end output to strings)
//
// write output to stdout, the standard output stream
//
// format is a character string. The format string is composed of zero or more directives.
// See man 3 printf for more detail.
//
// This function does not handle the following features:
// * flag characters
// * field width
// * precision
// * length modifiers

#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char *str_arg;
	int int_arg;
	char char_arg;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
			case 'c':
				char_arg = va_arg(args, int);
				count += putchar(char_arg);
				break;
			case 's':
				str_arg = va_arg(args, char *);
				if (str_arg == NULL)
					str_arg = "(null)";
				while (*str_arg)
				{
					count += putchar(*str_arg);
					str_arg++;
				}
				break;
			case 'd':
			case 'i':
				int_arg = va_arg(args, int);
				// **Correction:** Check for negative numbers and print the sign.
				if (int_arg < 0) {
					count += putchar('-');
					int_arg *= -1;
				}
				count += print_number(int_arg);
				break;
			case '%':
				count += putchar('%');
				break;
			default:
				count += putchar('%');
				count += putchar(*format);
				break;
			}
		}
		else
		{
			count += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

