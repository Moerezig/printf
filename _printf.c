#include "main.h"


/**
 * _printf - custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */


int _printf(const char *format, ...)
{
	va_list list;
	int count = 0;

	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count = handle_char(list, count);
					break;
			case 's':
				count = handle_string(list, count);
				break;
			case 'd':
			case 'i':
				count = handle_int(list, count);
				break;
			case '%':
				count += _putchar('%');
					break;
			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
			}}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(list);
	return (count);
}
