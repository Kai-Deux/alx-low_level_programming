#include "main.h"

/**
 * _strpbrk - find first occurrence of any of a set of bytes
 * @s: string
 * @accept: string of bytes to search for
 * 
 * Return: pointer to first occurrence of any of the bytes in accept
 */
char *_strpbrk(char *s, char *accept)
{
	int i = 0, j = 0;

	while (s[i] != '\0')
	{
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				return (&s[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
