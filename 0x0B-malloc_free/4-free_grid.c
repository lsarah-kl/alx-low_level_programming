#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a two dimension array
 * @grid: two dimension grid
 * @height: height dimension of grid
 * Return: nothing
 *
 */
void free_grid(int **grid, int height)
{
	int i;
		
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
