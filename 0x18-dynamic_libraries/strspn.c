#include "main.h"

/**
 * _strspn - find first occurrence of any of a set of bytes
 * @s: string
 * @accept: string of bytes to search for
 * 
 * Return: number of bytes in the initial segment of s which consist only
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0, j = 0, count = 0;

	while (s[i] != '\0')
	{
		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
			{
				count++;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}
