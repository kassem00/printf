#include "main.h"
/**
 * _printf - Print function
 * @in_for: input text formated.
 * Return: int value.
 */
int _printf(const char *format, ...)
{
va_list arg;
int count = 0;
const char *p;

va_start(arg, format);

for (p = format; *p; ++p)
{
if (*p != '%')
{
putchar(*p);
++count;
} else {
switch (*++p)
{
case 'c':
{
char c = va_arg(arg, int);
putchar(c);
++count;
break;
}
case 's':
{
const char *s = va_arg(arg, const char *);
while (*s)
{
putchar(*s++);
++count;
}
break;
}
case '%': {
putchar('%');
++count;
break;
}
}
}
}
va_end(arg);
return count;
}