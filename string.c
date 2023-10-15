#include "main.h"

/**
 * _print_string - Prints a string
 * @args: The va_list containing the arguments
 *
 * Return: The number of characters printed, or -1 on error
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
		str = "(null)";

	int length = 0;
	while (str[length] != '\0')
		length++;

	char *temp_str = malloc(sizeof(char) * (length + 1));
	if (temp_str == NULL)
	{
		return -1;
	}

	int i;
	for (i = 0; i < length; i++)
		temp_str[i] = str[i];
	temp_str[length] = '\0';

	while (*temp_str)
	{
		count += _putchar(*temp_str);
		temp_str++;
	}

	free(temp_str);

	return count;
}
