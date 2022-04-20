#include "main.h"

int printf_unsigned(unsigned long number, int radix, int is_upper)
{
	char buffer[32], *hexChars;
	int pos = 0, output_length = 0;
	char hexChars_lower[18] = "0123456789abcdef";
	char hexChars_upper[18] = "0123456789ABCDEF";

	hexChars = is_upper ? hexChars_upper : hexChars_lower;

	do {
		unsigned long rem = number % radix;
		number /= radix;
		buffer[pos++] = hexChars[rem];
	} while (number > 0);

	while (--pos >= 0)
		output_length += _putchar(buffer[pos]);

	return (output_length);
}

int printf_signed(long number, int radix, int is_upper)
{
	int output_length = 0;
	if (number < 0)
	{
		output_length += _putchar('-');
		output_length += printf_unsigned((number * -1) , radix, is_upper);
	}
	else output_length += printf_unsigned(number, radix, is_upper);

	return (output_length);
}
