#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all possible different combinations of two digits
 * separated by ", " and in ascending order
 * Only the smallest combination of two digits is printed
 * Numbers are printed using the putchar function
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i, j;

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
		putchar(i % 10 + '0');
		putchar(j % 10 + '0');

		if (i == 8 && j == 9)
			break;

		putchar(',');
		putchar(' ');
		}
	}

	putchar('\n');

	return (0);
}
