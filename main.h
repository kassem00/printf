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
#endif
