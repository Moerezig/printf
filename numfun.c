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
