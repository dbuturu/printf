#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
void normal_state(const char *format, int i, int *state, int *output_length);
int specifiers_state(
		const char *format,
		va_list args,
		int i,
		int output_length
		);
int _putn(int *num);
int counter (char *string);
char *intstring(int n);

#endif /* MAIN_H */