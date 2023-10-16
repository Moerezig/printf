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

/**
 * print_reversed_string - Prints a given string in reverse order
 * @str: The string to be printed in reverse
 *
 * Return: The length of the string
 */
int print_reversed_string(const char *str)
{
	if (str == NULL)
		return (0);

	int length = 0;

	while (str[length] != '\0')
		length++;

	for (int i = length - 1; i >= 0; i--)
		_putchar(str[i]);

	return (length);
}

/**
 * print_rot13_string - Applies ROT13 cipher to a given string and print
 * @str: The string to be ciphered and printed
 *
 * Return: The number of characters printed
 */
int print_rot13_string(const char *str)
{
	if (str == NULL)
		return (0);

	int count = 0;

	while (*str)
	{
		
	char c = *str;
		
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M'))
			c += 13;
		else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z'))
			c -= 13;

		count += _putchar(c);

		str++;
	}
		return (count);
}
