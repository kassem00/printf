#include "main.h"

/**
 * parse_flags - Parses the active flags in a format string
 * @format: Formatted string in which to print the arguments
 * @index: Index of the format string to start parsing flags from
 * Return: Integer value representing the active flags in the format string
 */
int parse_flags(const char *format, int *index)
{
/* - + 0 # ' ' */
/* 1 2 4 8  16 */
static const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
static const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
int curr_index = *index + 1;
int flags = 0;
while (format[curr_index] != '\0')
{
int j;
for (j = 0; FLAGS_CH[j] != '\0'; j++)
{
if (format[curr_index] == FLAGS_CH[j])
{
flags |= FLAGS_ARR[j];
break;
}
}
if (FLAGS_CH[j] == '\0')
{
break;
}
curr_index++;
}
*index = curr_index;
return flags;
}
