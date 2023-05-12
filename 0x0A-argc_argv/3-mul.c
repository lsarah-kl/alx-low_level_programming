#include <stdio.h>
#include "main.h"

/**
 * main - Multiplies two numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error\n");
        return 1;
    }

    int num1 = _atoi(argv[1]);
    int num2 = _atoi(argv[2]);

    int result = num1 * num2;

    printf("%d\n", result);

    return 0;
}
