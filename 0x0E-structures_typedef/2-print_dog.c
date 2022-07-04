#include "dog.h"
#include <stdlib.h>
#include <stdio.h>
/**
* print_dog - function
* @d: pointer to struct dog
*
* Description: function to print a struct dog
* Return: ptr to struct dog.
*/
void print_dog(struct dog *d)
{
	struct dog;

	if (d == NULL)
		return;
	if (d->name == NULL)
		d->name = "(nil)";
	if (d->owner == NULL)
		d->owner = "(nil)";
	printf("Name: %s\n", d->name);
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner);
}
