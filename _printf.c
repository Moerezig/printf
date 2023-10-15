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

	while (*format) {
		if (*format == '%') {
			format++;

			switch (*format) {
			case 'c':
				char_arg = va_arg(args, int);
				count += _putchar(char_arg);
				break;
			case 's':
				str_arg = va_arg(args, char *);
				if (str_arg == NULL)
					str_arg = "(null)";
				count += _print_string(str_arg);
				break;
			case 'd':
			case 'i':
				int_arg = va_arg(args, int);
				count += _print_number(int_arg, 10);
				break;
			case 'u':
				uint_arg = va_arg(args, unsigned int);
				count += _print_unsigned_number(uint_arg, 10);
				break;
			case 'b':
				uint_arg = va_arg(args, unsigned int);
				count += _print_binary(uint_arg);
				break;
			case '%':
				count += _putchar('%');
				break;
			default:
				count += _putchar('%');
				count += _putchar(*format);
				break;
			}
		} else {
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _putchar - put a character to stdout
 * @c: The character to print
 * Return: The number of characters printed
 */
int _putchar(int c)
{
	return write(1, &c, 1);
}

/**
 * _print_string - print a string to stdout
 * @str: The string to print
 * Return: The number of characters printed
 */
int _print_string(char *str)
{
	int count = 0;

	while (*str) {
		count += _putchar(*str);
		str++;
	}

	return count;
}

/**
 * _print_number - print an integer to stdout
 * @n: The integer to print
 * @base: The base to use for printing
 * Return: The number of characters printed
 */
int _print_number(int n, int base)
{
	int count = 0;
	char *digits = "0123456789ABCDEF";

	if (n < 0) {
		count += _putchar('-');
		n *= -1;
	}

	if (n >= base) {
		count += _print_number(n / base, base);
		count += _putchar(digits[n % base]);
	} else {
		count += _putchar(digits[n]);
	}

	return count;
}

/**
 * _print_binary - print a binary number to stdout
 * @n: The binary number to print
 * Return: The number of characters printed
 */
int _print_binary(unsigned int n)
{
	int count = 0;

	while (n) {
		count += _putchar((n & 1) + '0');
		n >>= 1;
	}

	return count;
}

