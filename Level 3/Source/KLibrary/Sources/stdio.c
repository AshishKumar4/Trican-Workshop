#include "stdio.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stdint.h"
#include "string.h"
#include "../../Drivers/VGA/vga.h"
#include "common.h"

int putchar(int ch)
{
    return vga_putchar((char)ch);
}

void print(const char* data, size_t data_length)
{
	for ( size_t i = 0; i < data_length; i++ )
		putchar((int) ((const unsigned char*) data)[i]);
}

void printint(uint32_t in)
{
    char tmp[16];
	itoa(in, tmp, 10);
	print(tmp, strlen(tmp));
}

int printf(const char* restrict format, ...)
{
    va_list parameters;
    va_start(parameters, format);

    int written = 0;
    size_t amount;
    bool rejected_bad_specifier = false;

    while ( *format != '\0' )
    {
        if ( *format != '%' )
        {
        print_c:
            amount = 1;
            while ( format[amount] && format[amount] != '%' )
                amount++;
            print(format, amount);
            format += amount;
            written += amount;
            continue;
        }

        const char* format_begun_at = format;

        if ( *(++format) == '%' )
            goto print_c;

        if ( rejected_bad_specifier )
        {
        _incomprehensible_conversion:
            rejected_bad_specifier = true;
            format = format_begun_at;
            goto print_c;
        }

        if ( *format == 'c' )
        {
            format++;
            char c = (char) va_arg(parameters, int /* char promotes to int */);
            print(&c, sizeof(c));
        }
        else if ( *format == 's' )
        {
            format++;
            const char* s = va_arg(parameters, const char*);
            print(s, strlen(s));
        }
        else if(*format == 'i' ||*format == 'd')
        {
            format++;
            int c = va_arg (parameters, int);
                        if(c < 0)
                        {
                            print("-", 1);
                            c = -c;
                        }
            printint(c);
        }
        else if(*format == 'l' || *format == 'u') //uint32_t
        {
            format++;
            uint32_t c = va_arg (parameters, uint32_t);
            printint(c);
        }
        else if(*format == 'p'||*format == 'g') //color
        {
            format++;
            int c = va_arg (parameters, int);
                        if(!c)
                            console_color = default_console_color;
                        else
                            console_color = c;
        }

        else if(*format == 'f') //float
        {
            format++;
            double c = va_arg (parameters, double);
                        if(c < 0)
                        {
                            print("-", 1);
                            c = -c;
                        }
                        uint32_t in = (uint32_t)(int)c;
                        double d = (double)c;
                        d -= in;
                        d *= 10000000;
                        printint(in);
                        print(".", 1);
                        in = (int)d;
                        printint(in);
        }

        else if(*format == 'x') //hex
        {
            format++;
                        print("0x", 2);
            uint32_t c = va_arg (parameters, uint32_t);
                        char tmp[10];
                        itoa(c, tmp, 16);
            print(tmp, strlen(tmp));
        }
        else
        {
            goto _incomprehensible_conversion;
        }
    }

    va_end(parameters);
    
    return written;
}

char tbuf[32];
char bchars[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

void itoa(unsigned i,char* buf, unsigned base)
{
    int pos = 0;
    int opos = 0;
    int top = 0;

    if (i == 0 || base > 16) {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    while (i != 0) {
        tbuf[pos] = bchars[i % base];
        pos++;
        i /= base;
    }
    top=pos--;
    for (opos=0; opos<top; pos--,opos++)
        {
        buf[opos] = tbuf[pos];
    }
    buf[opos] = 0;
}

int puts(const char* string)
{
	return printf("%s\n", string);
}