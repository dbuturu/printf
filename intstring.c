#include <stdlib.h>
#include "main.h"

/**
 * intstring - converts int to string
 * @n: integer
 * Return: string
 */

char *intstring(int n, int r)
{
	long x;
	int count, adjust;
	char *string;

	string = malloc(sizeof(char) * r);

	if (string == NULL)
		return (NULL);
	x = n;

	count = 0;

	if (n < 0)
	{
		string[count++] = '-';

		x = x * -1;
	}

	if (x > 9)
	{
		adjust = r;

		while (x / adjust >= r)
			adjust = adjust * r;

		string[count++] = ((x / adjust) + '0');

		while (adjust >= r)
		{
			adjust = adjust / r;
			string[count++] = (((x / adjust) % r) + '0');
		}
	}
	else
		string[count++] = x + '0';

	string[count] = 0;
	return (string);
}

