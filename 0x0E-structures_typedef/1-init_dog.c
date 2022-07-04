#include "dog.h"
#include <stdlib.h>
/**
* init_dog - function
* @d: pointer to struct dog
* @name: name of doggo
* @age: age of doggo
* @owner: name of owner
*
* Description: function to initialize a variable of type struct dog
* Return: ptr to struct dog.
*/
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != '\0')
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}

}
