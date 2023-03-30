#include "main.h"

int _printf(const char *format, ...)
{
	va_list list;
	int printed_chars = 0, buff_ind = 0, flags, width, precision, size;
	char buffer[BUFF_SIZE] = {0};
	size_t i;

	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += buff_ind;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed_chars += handle_print(format, &i, list, buffer, flags, width, precision, size);
		}
	}

	print_buffer(buffer, &buff_ind);
	printed_chars += buff_ind;
	va_end(list);

	return (printed_chars);
}

void print_buffer(char buffer[], int *buff_ind)
{
	write(1, buffer, *buff_ind);
	*buff_ind = 0;
}
