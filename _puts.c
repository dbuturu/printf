#include "main.h"
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

/**
 * _putn- print num
 *
 * @num: int num
 * Return: length of str
 */

int _putn(int *num)
{
	return (_puts((*char)num));
}

