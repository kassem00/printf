#ifndef _PUTCHAR_H
#define _PUTCHAR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#define constchartype 0
#define chartype 1
#define inttype 2

int _printf(const char *format, ...);
int _putchar(char c);void incress_print(int *count, ...);
void incress_print(int *count, ...);
int parse_size(const char *format, int *index);
int parse_precision(const char *format, int *index, va_list list);
int parse_flags(const char *format, int *index);
int parse_width(const char *format, int *i, va_list list);
int parse_handle(const char *fmt, int *ind, va_list list, char buffer[],\
int flags, int width, int precision, int size);
#endif
