#include <stddef.h>
#include "slide_line.h"

#define SLIDE_LEFT  0
#define SLIDE_RIGHT 1

/**
 * slide_line - Slide and merge integers in an array to the left or right.
 * @line: Array of integers to be slid and merged.
 * @size: Number of elements in the array.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT.
 *
 * Return: 1 upon success, 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
            {
                for (j = i + 1; j < size; j++)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }

            for (k = i + 1; k < size; k++)
            {
                if (line[k] == line[i])
                {
                    line[i] *= 2;
                    line[k] = 0;
                    break;
                }
                else if (line[k] != 0)
                {
                    break;
                }
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        for (i = size - 1; (int)i >= 0; i--)
        {
            if (line[i] == 0)
            {
                for (j = i - 1; (int)j >= 0; j--)
                {
                    if (line[j] != 0)
                    {
                        line[i] = line[j];
                        line[j] = 0;
                        break;
                    }
                }
            }

            for (k = i - 1; (int)k >= 0; k--)
            {
                if (line[k] == line[i])
                {
                    line[i] *= 2;
                    line[k] = 0;
                    break;
                }
                else if (line[k] != 0)
                {
                    break;
                }
            }
        }
    }

    return 1;
}
