#include "main.h"

/**
 * parse_size - Parses the size modifier for printing from a format string
 * @format: Formatted string in which to print the arguments
 * @index: Index of the format string to start parsing size modifier from
 *
 * Return: The parsed size modifier, or 0 if no size modifier was found
 */
int parse_size(const char *format, int *index)
{
	int curr_index = *index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
	{
		size = S_LONG;
		curr_index++;
	}
	else if (format[curr_index] == 'h')
	{
		size = S_SHORT;
		curr_index++;
	}

	*index = size ? curr_index - 1 : *index;
	return size;
}
