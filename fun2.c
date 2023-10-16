#include "main.h"

/**
 * print_octal - Prints an unsigned int in octal
 * @num: The unsigned integer to print
 * Return: The number of chars
 */

int print_octal(unsigned int num)
{
	if (num == 0)
		return (_putchar('0'));

	if (num / 8)
		print_octal(num / 8);

	return (_putchar((num % 8) + '0'));
}


/**
 * print_hexadecimal - Prints an unsigned int in hexadecimal
 * @num: The unsigned integer
 * @uppercase: Flag
 * Return: The number of chars
 */

int print_hexadecimal(unsigned int num, int uppercase)
{
	if (num == 0)
		return (_putchar('0'));

	if (num / 16)
		print_hexadecimal(num / 16, uppercase);

	int remainder = num % 16;
	if (remainder < 10)
		return (_putchar(remainder + '0'));
	else
	{
		char letter = uppercase ? 'A' : 'a';
		return (_putchar(remainder - 10 + letter));
	}
}
