#include "main.h"
int _printf(const char *format, ...)
{
    int i, count = 0;
    va_list arg_list;

    va_start(arg_list, format);

    for (i = 0; format[i] != '\0'; i++)
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    count += putchar(va_arg(arg_list, int));
                    break;
                case 's':
                    count += print_str(va_arg(arg_list, char *));
                    break;
                case 'd':
                case 'i':
                    count += print_int(va_arg(arg_list, int));
                    break;
                case 'u':
                    count += print_unsigned(va_arg(arg_list, unsigned int), 10, 0);
                    break;
                case 'o':
                    count += print_unsigned(va_arg(arg_list, unsigned int), 8, 0);
                    break;
                case 'x':
                    count += print_unsigned(va_arg(arg_list, unsigned int), 16, 0);
                    break;
                case 'X':
                    count += print_unsigned(va_arg(arg_list, unsigned int), 16, 1);
                    break;
                case 'p':
                    count += print_address(va_arg(arg_list, void *));
                    break;
                case '%':
                    count += putchar('%');
                    break;
                default:
                    count += putchar('%');
                    count += putchar(format[i]);
                    break;
            }
        }
        else
        {
            count += putchar(format[i]);
        }
    }

    va_end(arg_list);

    return count;
}
