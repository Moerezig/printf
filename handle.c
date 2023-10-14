#include "main.h"


/**
 * handle_char - handles the %c conversion specifier
 * @list: The va_list containing the arguments
 * @count: The count of characters printed
 * Return: The updated count of characters printed
 */


int handle_char(va_list list, int count)
{
	char c;

	c = va_arg(list, int);
	count += _putchar(c);
	return (count);
}




/**
 * handle_string - handles the %s conversion specifier
 * @list: The va_list containing the arguments
 * @count: The count of characters printed
 * Return: The updated count of characters printed
*/


int handle_string(va_list list, int count)
{
	char *str;
	int i;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		count += _putchar(str[i]);
		i++;
	}
	return (count);
}



/**
 * handle_int - handles the %d and %i conversion specifiers
 * @list: The va_list containing the arguments
 * @count: The count of characters printed
 * Return: The updated count of characters printed
 */


int handle_int(va_list list, int count)
{
	int i;
	int div;
	int n;

	i = va_arg(list, int);
	if (i < 0)
	{
		count += _putchar('-');
		n = -i;
	}
	else
		n = i;

	divisor = 1;
	while (n / div > 9)
		divisor *= 10;

	while (div != 0)
	{
		count += _putchar('0' + (n / div));
		n %= div;
		div /= 10;
	}

	return (count);
}
