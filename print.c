#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * @f: format to print
 * @i: print character
 * return: sucssec
 */
    int _printf(const char *format, ...)
{
    unsigned i = 0, *f = 0;
    va_list __args;
    va_start(args, *format);
    while (*frmat[i] != NULL; i+ 1)
    {
        if (*format[i] != '%')
        {
                putchar(*format[i])
        }
        else if (*frmat[i+1] == 'c')
        {
            putchar(va_arg(args,int));
            i+ +;
        }
        else (*format[i +1 == 's'])
        {

        }
    }
        i += 1;
    return(i);
}


