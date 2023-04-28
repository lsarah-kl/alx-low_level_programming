#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Description: Tests the print_remaining_days function with the date
 *              February 29th, 2000, which is a leap year.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int month = 2;
	int day = 29;
	int year = 2000;

	printf("Testing print_remaining_days with date %02d/%02d/%04d\n", month, day, year);
	print_remaining_days(month, day, year);

	return 0;
}
