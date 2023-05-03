#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the head of the linked list
 *
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *current = *head;
    int count = 0, i;
    int *stack;

    /* Count the number of nodes in the linked list */
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    /* Allocate memory for the stack */
    stack = malloc(sizeof(int) * count);

    /* Push the values of the linked list onto the stack */
    current = *head;
    for (i = 0; i < count; i++)
    {
        stack[i] = current->n;
        current = current->next;
    }

    /* Traverse the linked list again and compare each value with the value at the top of the stack */
    current = *head;
    for (i = count - 1; i >= 0; i--)
    {
        if (stack[i] != current->n)
        {
            free(stack);
            return (0);
        }
        current = current->next;
    }

    /* Free the stack and return 1 (is a palindrome) */
    free(stack);
    return (1);
}

