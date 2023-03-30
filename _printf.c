#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed (excluding null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int length = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					length += printf("%c", va_arg(args, int));
					break;
				case 's':
					length += printf("%s", va_arg(args, char *));
					break;
				case '%':
					length += printf("%%");
					break;
				case 'd':
				case 'i':
					length += printf("%d", va_arg(args, int));
					break;
				case 'u':
					length += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					length += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					length += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					length += printf("%X", va_arg(args, unsigned int));
					break;
				case 'p':
					length += printf("%p", va_arg(args, void *));
					break;
				default:
					length += printf("%%%c", *format);
			}
		}
		else
		{
			length += putchar(*format);
		}

		format++;
	}

	va_end(args);

	return length;
}
