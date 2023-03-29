#ifndef _PUTCHAR_H
#define _PUTCHAR_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
int _printf(const char *format, ...);
void incress_print(int *count, ...);
int _putchar(char c);
static int num_digits(int n);
static void print_char_n(char c, int n);
static void print_decimal(int n);
static void print_string(char *s);
#endif
