2-strlen.c

#include "main.h"
/**
 * _strlen - returns the len of a str
 * @s: the string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

