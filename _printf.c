#include "main.h"
int _printf(const char *format, ...)
{
	va_list args;
	char c, *s;
	int n = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char) va_arg(args, int);
					n += write(1, &c, 1);
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					n += write(1, s, strlen(s));
					break;
				case '%':
					n += write(1, "%", 1);
					break;
				default:
					n += write(1, "%", 1);
					n += write(1, &(*format), 1);
					break;
			}
		}
		else
		{
			n += write(1, &(*format), 1);
		}
		format++;
	}

	va_end(args);
	return (n);
}