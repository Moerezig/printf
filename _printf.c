#include "main.h"

/**
 *  * _printf - custom printf function
 *   * @format: The format string
 *    * Return: The number of characters printed
 *    */
int _printf(const char *format, ...)
{
  va_list args;
  int count = 0;

  while (*format) {
      if (*format == '%') {
            format++;
      
            switch (*format) {
	          case 'c':
	            count += _putchar(va_arg(args, int));
	            break;
	          case 's':
	            count += _print_string(va_arg(args, char *));
	            break;
	          case 'd':
	          case 'i':
	            count += _print_number(va_arg(args, int));
	            break;
	          case 'u':
	            count += _print_unsigned_number(va_arg(args, unsigned int));
	            break;
	          case 'b':
	            count += _print_binary(va_arg(args, unsigned int));
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

  return count;
}

/**
 *  * _putchar - put a character to stdout
 *   * @c: The character to print
 *    * Return: The number of characters printed
 *    */
int _putchar(int c)
{
  return write(1, &c, 1);
}

/**
 *  * _print_string - print a string to stdout
 *   * @str: The string to print
 *    * Return: The number of characters printed
 *    */
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
 *  * _print_number - print an integer to stdout
 *   * @n: The integer to print
 *    * Return: The number of characters printed
 *    */
int _print_number(int n)
{
  int count = 0;
  int sign = 1;

  if (n < 0) {
      sign = -1;
      n *= -1;
      count += _putchar('-');
    }

  if (n >= 10) {
      int digit = n % 10;
      n /= 10;
      count += _print_number(n);
      count += _putchar(digit + '0');
    } else {
        count += _putchar(n + '0');
      }

  return count;
}

/**
 *  * _print_unsigned_number - print an unsigned integer to stdout
 *   * @n: The unsigned integer to print
 *    * Return: The number of characters printed
 *    */
int _print_unsigned_number(unsigned int n)
{
  int count = 0;

  if (n >= 10) {
      int digit = n % 10;
      n /= 10;
      count += _print_unsigned_number(n);
      count += _putchar(digit + '0');
    } else {
        count += _putchar(n + '0');
      }

  return count;
}

/**
 *  * _print_binary - print a binary number to stdout
 *   * @n: The binary number to print
 *    * Return: The number of characters printed
 *    */
int _print_binary(unsigned int n)
{
  int count = 0;

  while (n) {
      count += _putchar((n & 1) + '0');
      n >>= 1;
    }

  return count;
}
