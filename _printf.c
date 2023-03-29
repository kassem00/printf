#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
/* Returns the number of digits in an integer */
static int num_digits(int n)
{
int count = 0;
do {
count++;
n /= 10;
} while (n != 0);
return count;
}

/* Prints a character n times */
static void print_char_n(char c, int n)
{
for (int i = 0; i < n; i++) {
putchar(c);
}
}
/* Prints an integer in decimal format */
static void print_decimal(int n)
{
if (n == 0) {
putchar('0');
return;
}
if (n < 0) {
putchar('-');
n = -n;
}
int num_digits = num_digits(n);
char buffer[num_digits + 1];
for (int i = num_digits - 1; i >= 0; i--) {
buffer[i] = n % 10 + '0';
n /= 10;
}
buffer[num_digits] = '\0';
printf("%s", buffer);
}

/* Prints a string */
static void print_string(char *s)
{
while (*s != '\0') {
putchar(*s);
s++;
}
}

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;
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
case 's':
{
char *s = va_arg(args, char *);
print_string(s);
count += strlen(s);
break;
}
case 'd':
case 'i':
{
int n = va_arg(args, int);
print_decimal(n);
count += num_digits(n);
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
return count;
}
