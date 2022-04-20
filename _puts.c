#include "main.h"
#include <stdio.h>
/**
 * _puts- print str
 *
 * @str: char *str
 * Return: length of str
 */

int _puts(char *str)
{
	int i;

	for (i = 0; *str != '\0'; ++i)
		_putchar(*str++);

	return (i);
}

int putn(int output_length, va_list args, int radix, int sign, int number, int is_upper)
{
        if (number == 1) {
                if (sign)
                        output_length += printf_signed(va_arg(args, int), radix, is_upper);
                else
                        output_length +=
                                printf_unsigned(va_arg(args, unsigned long), radix, is_upper);
                number = output_length;
        }
        return number;
}
