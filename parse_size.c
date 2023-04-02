#include "main.h"

/**
 * parse_size - Parses the size modifier for printing from a format string
 * @format: Formatted string in which to print the arguments
 * @index: Index of the format string to start parsing size modifier from
 *
 * Return: The parsed size modifier, or 0 if no size modifier was found
 */
int parse_size(const char *format, int *i)
{
int curr_i = *i + 1;
int size = 0;
if (format[curr_i] == 'l')
size = S_LONG;
else if (format[curr_i] == 'h')
size = S_SHORT;
if (size == 0)
*i = curr_i - 1;
else
*i = curr_i;
return (size);
}
