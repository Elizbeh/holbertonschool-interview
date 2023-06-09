<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>

=======
>>>>>>> 8df6c2a15fcab05b00b1abe097401dbab7003f6c
#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */

<<<<<<< HEAD
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j, unstable;

    do {
        unstable = 0;

        /* Add two sandpiles */
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                grid1[i][j] += grid2[i][j];
            }
        }

        /* Topple sandpile until it's stable */
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    unstable = 1;
                    grid1[i][j] -= 4;
                    if (i > 0)
                        grid1[i - 1][j]++;
                    if (i < 2)
                        grid1[i + 1][j]++;
                    if (j > 0)
                        grid1[i][j - 1]++;
                    if (j < 2)
                        grid1[i][j + 1]++;
                }
            }
        }

        /* Print the grid if it's unstable */
        if (unstable) {
            printf("=\n");
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (j)
                        printf(" ");
                    printf("%d", grid1[i][j]);
                }
                printf("\n");
            }
        }

    } while (unstable);

=======

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0, j = 0;
	int wistle[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (grid1_unstable(grid1, wistle))
	{
		/* print unstable grid before toppling*/
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (wistle[i][j])
					topple(grid1, i, j);
			}
		}
	}
}


/**
 *
 *
*/ 


int grid1_unstable(int grid1[3][3], int wistle[3][3])
{
	int check = 0, i = 0, j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				check = 1;
				wistle[i][j] = 1;
			}
			else
				wistle[i][j] = 0;
		}
	}
	return (check);
}


/**
 *
 *
 */

void topple(int grid1[3][3], int i, int j)
{
	grid1[i][j] -= 4;
	if (i - 1 >= 0)
		grid1[i - 1][j] += 1;
	if (i + 1 < 3)
		grid1[i + 1][j] += 1;
	if (j - 1 >= 0)
		grid1[i][j - 1] += 1;
	if (j + 1 < 3)
		grid1[i][j + 1] += 1;
}

/**
 * print_grid - prints individual grid
 * @grid: 3x3 grid of integers to print
 *
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
>>>>>>> 8df6c2a15fcab05b00b1abe097401dbab7003f6c
