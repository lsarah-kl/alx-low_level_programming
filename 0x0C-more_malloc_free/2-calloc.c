#include <stdlib.h>
#include "main.h"

/**
 * *_memset - fill memory with byte
 * @s: memory spce to fill
 * @b: character we copy
 * @n: times to copy b
 *
 * Return: pointer to the memory space s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}

/**
 * *_calloc - allocate mem to an array
 * @nmemb: n elements in the array
 * @size: size of element
 *
 * Return: pointer to allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	ptr = malloc(size * nmemb);

	if (ptr == NULL)
		return (NULL);

	_memset(ptr, 0, nmemb * size);

	return (ptr);
}

