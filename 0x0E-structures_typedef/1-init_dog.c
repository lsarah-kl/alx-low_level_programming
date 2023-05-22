#include <stdlib.h>
#include "dog.h"

/**
 * init_dog - initialize variable of type struct dog
 * @d: pointer the points to struct dog so it can initialize
 * @name: the name to initialize
 * @age: the age to initialize
 * @owner: the owner to initialize
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	d->name = name;
	d->age = age;
	d->owner = owner;
}
