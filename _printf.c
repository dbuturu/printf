#include "main.h"
#include <stdio.h>

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
	switch (format[i])
	{
		case 'c':
			output_length += _putchar((char)va_arg(args, int));
			break;

		case 's':
			output_length += _puts(va_arg(args, char *));
			break;

		case '%':
			output_length += _putchar('%');
			break;
		case 'd':
		case 'i':
			output_length += _putn(va_arg(args, int *));
			break;
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
		};

	return (output_length);
}

