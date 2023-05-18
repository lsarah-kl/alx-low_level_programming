#include <stdlib.h>
#include "main.h"

/**
 * *malloc_checked - allocate memory space using malloc
 * @b: bytes to allocate
 *
 * Return: a pointer pointing to allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);

	if (ptr == NULL)
		exit(98);

	return (ptr);
}

