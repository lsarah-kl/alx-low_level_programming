#include "3-calc.h"

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);

/**
 * op_add - function that returns the sum of two numbers.
 * @a: 1st number.
 * @b: 2nd number.
 *
 * Return: The sum of a and b.
 */
int op_add(int a, int b)
{
	return (a + b);
}

int op_sub(int a, int b)
{
	return (a - b);
}
/**
 * op_mul - function that returns the product of two numbers.
 * @a: 1st number.
 * @b: 2nd number.
 *
 * Return: The product of a and b.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

int op_div(int a, int b)
{
	return (a / b);
}
/**
 * op_mod - function that returns the remainder of division of two numbers.
 * @a: 1st number.
 * @b: 2nd number.
 *
 * Return: The remainder of the division of a by b.
 */
int op_mod(int a, int b)
{
	return (a % b);
}

