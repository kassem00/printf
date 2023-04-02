#include "main.h"

/**
 * parse_flags - Parses the active flags in a format string
 * @format: Formatted string in which to print the arguments
 * @index: Index of the format string to start parsing flags from
 * Return: Integer value representing the active flags in the format string
 */
int parse_flags(const char *format, int *i)
{
/* - + 0 # ' ' */
/* 1 2 4 8 16 */
int j, curr_i;
int flags = 0;
const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH,
F_SPACE, 0};
for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
{
for (j = 0; FLAGS_CH[j] != '\0'; j++)
if (format[curr_i] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
if (FLAGS_CH[j] == 0)
break;
}
*i = curr_i - 1;
return (flags);
}