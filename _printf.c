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
char c, *s;
va_start(args, format);
while (*format != '\0') {
if (*format == '%') {
format++;
switch (*format) {
case 'c':
c = va_arg(args, int);
count += putchar(c);
break;
case 's':
s = va_arg(args, char *);
count += printf("%s", s);
break;
case '%':
count += putchar('%');
break;
default:
count += putchar('%');
count += putchar(*format);
break;
}
}
else
{
count += putchar(*format);
}
format++;
}
va_end(args);
return count;
}
