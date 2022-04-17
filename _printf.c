#include "main.h"
#include <stdio.h>

#define NORMAL_STATE 0
#define SPECIFIERS_STATE 1

/**
 *
 */

int _printf(const char *format, ...) {

  va_list args;
  int i, state, output_length;

  va_start(args, format);
  state = NORMAL_STATE;
  for (i = 0; format[i] != '\0'; i++) {
    switch (state) {
    case NORMAL_STATE:
      switch (format[i]) {
      case '%':
        state = SPECIFIERS_STATE;
        break;
      default:
        output_length += _putchar(format[i]);
        break;
      }
      break;

    case SPECIFIERS_STATE:
      switch (format[i]) {
      case 'c':
        output_length += _putchar((char)va_arg(args, int));
        break;

      case 's':
        output_length += _puts(va_arg(args, char *));
        break;

      case '%':
        output_length += _putchar('%');
        break;
      }
      state = NORMAL_STATE;
      break;
    }
  }

  return (output_length);
}
