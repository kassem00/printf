#include "main.h"

/**
 * _printf - prints output according to a format.
 * @format: A pointer to a string to be printed.
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
 int count = 0;
 va_list args;
 int i;
 char *str;

 va_start(args, format);

 for (i = 0; format && format[i]; i++)
 {
if (format[i] == '%')
{
switch (format[++i])
{
 case 'c':
putchar(va_arg(args, int));
count++;
break;
 case 's':
str = va_arg(args, char *);
if (!str)
str = "(null)";
incress_print(&count, str, constchartype);
break;
 case '%':
putchar('%');
count++;
break;
 default:
putchar('%');
putchar(format[i]);
count += 2;
break;
}
}
else
{
putchar(format[i]);
count++;
}
}
va_end(args);
return (count);
}
void incress_print(int *count, ...)
{
    va_list args;
    va_start(args, count);
    while (*count != INT_MAX)
    {
        if (va_arg(args, int) == chartype)
            putchar(va_arg(args, int));
        else if (va_arg(args, int) == constchartype)
            fputs(va_arg(args, const char *), stdout);
        else if (va_arg(args, int) == inttype)
            printf("%d", va_arg(args, int));
        else
            break;
        (*count)++;
    }
    va_end(args);
}
