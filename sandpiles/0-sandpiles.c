#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */

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

