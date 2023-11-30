#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where the value is located,
 * or NULL if the value is not present in the list or if the head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current = list, *express = list;

    if (list == NULL)
        return NULL;

    while (express && express->express) {
        printf("Value checked at index [%lu] = [%d]\n",
               express->index, express->n);

        if (express->n >= value)
            break;

        current = express;
        express = express->express;
    }

    printf("Value found between indexes [%lu] and [%lu]\n",
           current->index, express->index);

    while (current && current->index <= express->index) {
        printf("Value checked at index [%lu] = [%d]\n",
               current->index, current->n);

        if (current->n == value)
            return current;

        current = current->next;
    }

    return NULL;
}
