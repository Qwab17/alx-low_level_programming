#include "main.h"

/**
 * free_grid - fxn that frees a 2 dimensional grid previously created
 * @grid: multidimensional array of integers
 * @height: height of the grid
 * Return: no return
 */

void free_grid(int **grid, int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height >= 0; height--)
			free(grid[height]);
		free(grid);
	}
}
