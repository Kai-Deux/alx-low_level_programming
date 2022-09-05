#include "main.h"

/**
 * _memcpy - copy memory area
 * 
 * @dest: destination memory area
 * @src: source memory area
 * @n: number of bytes to copy
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	while (n--)
		*dest++ = *src++;
	return dest;
}
