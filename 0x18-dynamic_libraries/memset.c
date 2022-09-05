#include "main.h"

/**
 * _memset - fill memory area
 * 
 * @s: memory area
 * @b: byte to fill
 * @n: number of bytes to fill
 * Return: pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	while (n--)
		*s++ = b;
	return s;
}
