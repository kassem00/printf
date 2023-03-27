#include "main.h"
/**
 * _printf - Print function
 * @in_for: input text formated.
 * Return: int value.
 */
int _printf(char* in_for, ...)
{

va_list VA;
unsigned int i, j;
va_start(VA, n);
for (i = 0; i < n; i++)
{
printf("%d", va_arg(VA, int));
if (separator != NULL && (i + 1) < n)
{
for (j = 0; separator[j] != '\0'; j++)
printf("%c", separator[j]);
}
}
printf("\n");
va_end(VA);
}