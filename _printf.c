#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdlib.h>

/**
 * _printf - prints any chars or strings given
 * @format: input string
 * prints string or char arguments
 * Return: total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, x, sum = 0;
	char *string, c;

	string = 0;
	c = 0;

	va_start(ap, format);
	/* check for null */
	if (format == NULL)
	{
		va_end(ap);
		return(-1);
	}
	/* loop to go through the printf format*/
	for (i = 0; format[i] != '\0'; i++)
	{
		/* deal with string without % */
		if (format[i] != '%')
		{
			write(1, &format[i], sizeof(char));
			sum++;
		}
		else 
		{
			switch (format[i + 1])
			{
				case '%':
					write(1, "%", sizeof(char));
					i++;
					sum++;
					break;
				case 'c':
					c = va_arg(ap, int);
					sum += _ch(c);
					i++;
					break;
				case 's':
					string = va_arg(ap, char *);
					if (string == NULL)
					{
						string = "(null)";
					}
					sum += _str(string);
					i++;
					break;
				case 'i':
				case 'd':
					x = va_arg(ap, int);
					sum += _num(x);
					i++;
					break;
				case ' ':
					return(-1);
					break;
				case '\0':
					if((i -1) > 0)
					{
						write(1, "%", sizeof(char));
						i++;
						sum++;
					}
					else
					{
						va_end(ap);
						return(-1);
					}
					break;
				default:
					write(1, "%", sizeof(char));
					sum++;
					break;
			}
		}
	}
	va_end(ap);

	return(sum);
}
