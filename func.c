#include "main.h"

/**
 * print_number - prints an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_number(num / 10);

	count += _putchar('0' + (num % 10));

	return (count);
}


/**
 * print_unsigned_number - prints an unsigned integer
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */

int print_unsigned_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned_number(n / 10);

	count += _putchar('0' + (n % 10));

	return (count);
}

/**
 * print_binary - prints an unsigned integer in binary format
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */

int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2);

	count += _putchar('0' + (n % 2));

	return (count);
}
