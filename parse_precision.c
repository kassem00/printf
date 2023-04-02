#include "main.h"

/**
 * parse_precision - Parses the precision for printing from a format string
 * @format: Formatted string in which to print the arguments
 * @index: Index of the format string to start parsing precision from
 * @list: List of arguments to be printed
 *
 * Return: The parsed precision, or -1 if no precision was found
 */
int parse_precision(const char *format, int *index, va_list list)
{
	int curr_index = *index + 1;
	int precision = -1;

	if (format[curr_index] != '.')
	{
		return precision;
	}

	precision = 0;
	curr_index++;

	while (format[curr_index] != '\0')
	{
		if (isdigit(format[curr_index]))
		{
			precision = precision * 10 + (format[curr_index] - '0');
			curr_index++;
		}
		else if (format[curr_index] == '*')
		{
			precision = va_arg(list, int);
			curr_index++;
			break;
		}
		else
		{
			break;
		}
	}

	*index = curr_index - 1;
	return precision;
}
