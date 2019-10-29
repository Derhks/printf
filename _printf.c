#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#define n "(nil)"

int _putstrings(char *str)
{
        int var1 = 0;
        if (*str == '\0')
        {
                return (var1);
        }
        while (*str != '\0')
        {
                _write(*str);
                str++;
                var1++;
        }
        return (var1);
}

void _putdouble(double num)
{
        double var1 = 0;
        int min = INT_MIN;
        var1 = var1 + num;
        if (var1 < 0 && num != min)
        {
                var1 -= var1 * 2;
                _write('-');
        }
        if (var1 >= 10 && num != min)
        {
                _putdouble((var1 / 10));
        }
        if (num == min)
        {
                _putstrings("-2147483648");
        }
        if (num != min)
                _write((int)var1 % 10 + '0');
}

int _putint(int num)
{
        int var1 = 1;
        double var2 = 0;
        var2 = num;
        _putdouble(var2);

        if (var2 < 0)
        {
                var2 -= var2 * 2;
                var1++;
        }
        while (var2 > 10)
        {
                var2 = var2 / 10;
                var1++;
        }

        return (var1);
}


int _printf(const char *format, ...)
{
	va_list string;
	unsigned int counter = 0;
	char *s;
	int var1 = 0;

va_start(string, format);
while (format != 0 && format[counter] != '\0')
{
	if (format[counter] == '%' && format[counter + 1] != '\0')
	{
		counter++;
		switch (format[counter])
		{
		case 'c':
			var1 += _write(va_arg(string, int));
			break;
		case 'd':
			var1 += _putint(va_arg(string, int));
			break;
		case 'i':
			var1 += _putint(va_arg(string, int));
			break;
		case 's':
			var1 += ((s = va_arg(string, char*)) == NULL) ? _putstrings(n) : _putstrings(s);
			break;
		default:
			var1 += _write('%');
			var1 += (format[counter] == '%') ? 0 : _write(format[counter]);
			break;
		}
	}
	else
	{
		var1 += (format[counter] == '%') ? -1 : _write(format[counter]);
	}
	if (format[counter] == 0)
	{
		_write(0);
	}
	counter++;
}
va_end(string);
return ((var1 == 0) ? -1 : var1);
}
