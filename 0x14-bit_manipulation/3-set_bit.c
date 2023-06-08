#include "main.h"

/**
 * set_bit - function that sets a bit at a given index to 1
 * @n: pointer to the number to be changed
 * @index: index of the bit to set to 1
 * Return: 1 in case of success, -1 in case of failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

