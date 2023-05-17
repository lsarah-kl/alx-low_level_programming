#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * str_concat - Concatenates two strings.
 * @s1: The first str to concate
 * @s2: The second str to concate
 *
 * Return: Pointer to a new allocated space in memory
 */
char *str_concat(char *s1, char *s2)
{
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";


	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	
	char *result = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL) {
		return NULL;
	}

	strcpy(result, s1);

	strcat(result, s2);

	return result;
}

/**
 * main - Entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char str1[] = " ";
	char str2[] = "";
	char *concatenated = str_concat(str1, str2);
	if (concatenated != NULL) {
		printf("Concatenated string: %s\n", concatenated);
		free(concatenated);  
	} else {
		printf("Failed to concatenate strings.\n");
	}
	return 0;
}
