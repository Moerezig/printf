#include "main.h"

/**
 * _print - prints an integer
 * @j: The integer
 * Return: The number of chars printed
 */

int _print(int j)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -j;
	}
	else
		num = j;
	if (num / 10)
		count += _print(num / 10);
	count += _putchar('0' + (num % 10));
	return (count);
}
