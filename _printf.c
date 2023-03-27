#include "main.h"
/**
 * _printf - Print function
 * @format: input text formated.
 * Return: int value.
 */
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == '%')
{
putchar('%');
count++;
}
else if (*format == 'c')
{
char c = va_arg(args, int);
putchar(c);
count++;
}
else if
(*format == 's')
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
putchar(*s);
s++;
count++;
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
return count;
}
