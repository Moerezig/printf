#include "main.h"

/**
* buffer_flush - flush the buffer
* @buffer: the buffer
* @buffer_index: the index of the buffer
* Return: nothing
*/

void buffer_flush(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
{
	buffer[*buffer_index] = '\0';
	write(1, buffer, *buffer_index);
	*buffer_index = 0;
}
}
