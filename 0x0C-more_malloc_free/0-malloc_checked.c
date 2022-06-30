#include <stdlib.h>
#include "main.h"
/**
 * malloc_checked - allocated memory using malloc
 * @b: unsigned integer
 * Return: a pointer to allocated memory or NULL if it fails
 */
void *malloc_checked(unsigned int b)
{
	void *s;

	s = malloc(b);

	if (s == NULL)
		exit(98);

	return (s);
}
