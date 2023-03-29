#ifndef _PUTCHAR_H
#define _PUTCHAR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

int _printf(const char *format, ...);
void incress_print(int *count, ...);
int _putchar(char c);
int get_flag(char s, flags_t *f);
int (*get_print(char s))(va_list, flags_t *);
#endif
