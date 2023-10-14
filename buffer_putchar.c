#include "main.h"

/**
* buffer_putchar - put a character
* @c: the character
* @buffer: the buffer
* @buffer_index: the index
* Rrturn: nothing
*/

void buffer_putchar(char c, char buffer[], int *buffer_index, int *chars_printed)
{
	if (*buffer_index >= BUFFER_SIZE - 1) 
	{
	buffer_flush(buffer, buffer_index);
	}

	buffer[*buffer_index] = c;
	(*buffer_index)++;
	(*chars_printed)++;
}
