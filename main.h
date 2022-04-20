#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _puts(char *str);
void normal_state(const char *format, int i, int *state, int *output_length);
int specifiers_state(const char *format, va_list args, int i,
                     int output_length);
int counter(char *string);
char *intstring(int n, int r);
int numbers(char fmt, int output_length, va_list args);
int is_number(char flag);
int printf_unsigned(unsigned long number, int radix, int is_upper);
int printf_signed(long number, int radix, int is_upper);
int putn(int output_length, va_list args, int radix, int sign, int number, int is_upper);
#endif
