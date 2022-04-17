#include "main.h"
/**
 * _puts- print str
 *
 * @str: char *str
 * Return: lenth of str
 */

int _puts(char *str) {
  int i;

  for (i = 0; *str != '\0'; ++i)
    _putchar(*str++);

  return (i);
}
