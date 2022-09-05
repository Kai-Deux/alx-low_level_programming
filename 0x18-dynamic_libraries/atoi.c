#include "main.h"

/**
 * _atoi - convert string to integer
 * 
 * @s: string to be converted 
 * Return: integer value
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, n = 0;

	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n * sign);
}
