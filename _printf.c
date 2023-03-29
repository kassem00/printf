#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
va_list args;
int count = 0;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
{
char c = va_arg(args, int);
putchar(c);
count++;
break;
}
case 's': {
char *s = va_arg(args, char *);
int n = 0;
while (s[n] != '\0')
{
putchar(s[n]);
n++;
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
{
putchar('%');
putchar(*format);
count += 2;
break;
}
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
