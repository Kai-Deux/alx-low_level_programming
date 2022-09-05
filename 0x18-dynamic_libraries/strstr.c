#include "main.h"

/**
 * _strspn - find first occurrence of any of a set of bytes
 * @haystack: string
 * @needle: string of bytes to search for
 * 
 * Return: number of bytes in the initial segment of s which consist only
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0, count = 0;

	while (haystack[i] != '\0')
	{
		while (needle[j] != '\0')
		{
			if (haystack[i] == needle[j])
			{
				count++;
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (needle);
}
