#include "main.h"



/**
 * _printf - custom printf function
 * @format: The format string
 * Return: The number of characters printed
*/

int _printf(const char *format, ...)
{
        va_list args;
        int count = 0;
        char *str_arg;
        int int_arg;
        char char_arg;
        unsigned int uint_arg;

        if (format == NULL)
                return (-1);

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
               		count += print_number(int_arg);
                	break;
                	case 'u':
                	uint_arg = va_arg(args, unsigned int);
                	count += print_unsigned_number(uint_arg);
                	break;
                case 'b':
                	uint_arg = va_arg(args, unsigned int);
                	count += print_binary(uint_arg);
                	break;
                case '%':
                	count += _putchar('%');
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
