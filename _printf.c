#include "main.h"

#define NORMAL_STATE 0
#define SPECIFIERS_STATE 1

/**
 * normal_state - Normal state cases.
 * @format: The input format.
 * @i: The counter.
 * @state: The state.
 * @output_length: The output length.
 */

void normal_state(const char *format, int i, int *state, int *output_length)
{
	switch (format[i])
	{
		case '%':
			(*state) = SPECIFIERS_STATE;
			break;
		default:
			(*output_length) += _putchar(format[i]);
			break;
	}
}

int numbers(char fmt, int output_length, int arg)
{
    switch (fmt) {
        case 'd':
        case 'i':
            output_length += _putn(arg, 10);
            break;

        case 'b':
            output_length += _putn(arg, 2);
            break;

        case 'u':
            output_length += _putn(arg, 10);
            break;

        case 'o':
            output_length += _putn(arg, 8);
            break;

        case 'x':
            output_length += _putn(arg, 16);
            break;

        case 'X':
            output_length += _putn(arg, 16);
            break;

        case 'p': {
            output_length += _putn(arg, 16);
            break;
        }
    }
    return output_length;
}

int is_number(char flag){
    char *flags = "dibuoxXp";
    int i, is_num = 0;

    for (i = 0; flags[i]; ++i)
        if (flags[i] == flag)
            is_num = 1;
   return is_num;
}

/**
 * specifiers_state - Specifiers state cases.
 * @format: The input format.
 * @args: Other params.
 * @i: The counter.
 * @output_length: The output length.
 * Return: The output length.
 */

int specifiers_state(
		const char *format,
		va_list args,
		int i,
		int output_length
		)
{
	char *string;

	switch (format[i])
	{
		case 'c':
			output_length += _putchar((char)va_arg(args, int));
			break;

		case 's':
			string = va_arg(args, char *);
			if (string == NULL)
			{
				string = "(null)";
			}
			output_length += _puts(string);
			break;

		case '\0':
		case '%':
			output_length += _putchar('%');
			break;

		case ' ':
			output_length = -1;
			break;

        case 'S':
            output_length += _puts(va_arg(args, char *));
            break;

        default:
			if(is_number(format[i])) {
                output_length = numbers(format[i], output_length, va_arg(args, int));
            }else
            {
                output_length += _putchar(format[--i]);
                output_length += _putchar(format[++i]);
                break;
            }
	}
	return (output_length);
}

/**
 * _printf - Produces output according to a format.
 * @format: The input format.
 * Return: The length of output.
 */

int _printf(const char *format, ...)
{

	va_list args;
	int i, state, output_length;

	va_start(args, format);
	output_length = 0;
	state = NORMAL_STATE;
	for (i = 0; format[i] != '\0'; i++)
		switch (state)
		{
			case NORMAL_STATE:
				normal_state(format, i, &state, &output_length);
				break;

			case SPECIFIERS_STATE:
				output_length = specifiers_state(format, args, i, output_length);
				state = NORMAL_STATE;
				break;
		}

	return (output_length);
}

