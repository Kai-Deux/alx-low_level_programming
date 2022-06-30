#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _realloc - reallocatrs a memory block usign malloc and free
 * @ptr: pointer to the previously allocated memory
 * @old_size: is the size,in bytes,of the allocated space for ptr
 * @new_size: is the size of the new memory block
 *
 * Return: if new_size > old_size, the added memory should not be initialized
 * if new_size == old_size return ptr
 * if ptr is NULL, malloc(new_size)
 * if new_size is zero and otr is not NULL Return NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *nptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		if (nptr == NULL)
			return (NULL);
		return (nptr);
	}
	else
	{
		if (new_size == 0)
		{
			free(ptr);
			return (NULL);
		}
	}
	nptr = malloc(new_size);
	if (nptr == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
	{
		nptr[i] = ((char *) ptr)[i];
	}
	free(ptr);
	return (nptr);
}
