#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 * @...: input
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == 'c')
incress_print(&count, va_arg(args, int));
else if (*format == 's')
incress_print(&count, va_arg(args, char *));
else if (*format == '%')
incress_print(&count, '%');
else if (*format == 'd' || *format == 'i')
incress_print(&count, va_arg(args, int));
else
{
incress_print(&count, '%');
incress_print(&count, *format);
}
}
else
incress_print(&count, *format);
format++;
}
va_end(args);
return (count);
}

/**
 * incress_print - Prints the value passed as parameter and increments the
 * counter of printed characters
 *
 * @count: A pointer to the counter of printed characters
 * @...:   The value to print
 */
void incress_print(int *count, ...)
{
char *str;
int n;
va_list args;

va_start(args, count);
if (*count < 0)
return;
if (va_arg(args, int) == 0)
{
*count += _putchar(0);
va_end(args);
return;
}
va_end(args);
va_start(args, count);
switch (va_arg(args, int))
{
case '%':
*count += _putchar('%');
break;
case 'c':
n = va_arg(args, int);
*count += _putchar(n);
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
*count += _putchar(*str);
str++;
}
break;
case 'd':
case 'i':
n = va_arg(args, int);
if (n < 0)
{
*count += _putchar('-');
n = -n;
}
if (n / 10)
incress_print(count, n / 10);
*count += _putchar('0' + n % 10);
break;
default:
*count = -1;
}
va_end(args);
}

#include "main.h"

/**
 * _putchar - Writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1, on error -1
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

