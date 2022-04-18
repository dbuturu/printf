#include <stdlib.h>
#include "main.h"
#include <stdio.h>

/**
 * intstring - converts int to string
 * @n: integer
 * Return: string
 */

char *intstring(int n)
{
	long x;
	int count, adjust;
	char *string;

	string = malloc(sizeof(char) * 10);

	if (string == NULL)
		return (NULL);
	x = n;

	count = 0;

	if (x < 0)
	{
		string[count++] = '-';

		x = x * -1;
	}

	if (x > 9)
	{
		adjust = 10;

		while (x / adjust >= 10)
			adjust = adjust * 10;

		string[count++] = ((x / adjust) + '0');

		while (adjust >= 10)
		{
			adjust = adjust / 10;
			string[count++] = (((x / adjust) %10) + '0');
		}
	}
	else 
		string[count++] = x + '0';

	string[count] = 0;
	return (string);
}
