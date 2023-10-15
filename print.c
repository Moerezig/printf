#include "main.h"

/**
 * _printf - custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
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
				count += _putchar(char_arg);
				break;
			case 's':
				str_arg = va_arg(args, char *);
				if (str_arg == NULL)
					str_arg = "(null)";
				while (*str_arg)
				{
					count += _putchar(*str_arg);
					str_arg++;
				}
				break;
			case 'd':
			case 'i':
				int_arg = va_arg(args, int);
				
				if (int_arg < 0) {
					count += _putchar('-');
					int_arg *= -1;
				}
				count += print_number(int_arg);
				break;
			case '%':
				if(*format == '%')
				{	
				count += _putchar('%');
				format++
				}
				else {
					count += _putchar('%');
					count += _putchar(*format);
				}
				break;

			default:

				count += _putchar('%');
				count += _putchar(*format);
				break;
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}


