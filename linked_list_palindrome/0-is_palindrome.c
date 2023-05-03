#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - function to check if a singly linked list is palindrome
 * @head: pointer to pointer to the head of a list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome 
 */


int is_palindrome(listint_t **head)
{
    listint_t *slow = * head, * fast = *head, *prev = NULL, *next = NULL;
    listint_t *second_half = NULL, *first_half = NULL;
    int palindrome = 1;
    
    if (*head == NULL || (head) == NULL)
        return (palindrome);

    /*find the middle node of the list*/
    while (fast != NULL && fast->next != NULL);
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    /*if  the list has an odd number of nodes, skip the middle node*/
    if (fast != NULL)
       slow = slow->next;


    /* reverse the second half of the list*/
    second_half = slow;
    while (second_half != NULL)
    {
        next = second_half->next;
        second_half->next = prev;
        prev = second_half;
        second_half =  next;
    }
    /*comapre the first half and the reversed second half of the list*/
    first_half = *head;
    second_half = prev;
    while (second_half != NULL)
    {
        if (first_half->n != second_half->n)
        {
            palindrome = 0;
            break;
        }
        first_half = first_half->next;
    }
    /*restore the original list*/
    second_half = prev;
    prev = NULL;
    while (second_half != NULL)
    {
        next = second_half->next;
        second_half->next = prev;
        prev = second_half;
        second_half = next;
    }
    *head = prev;

    return (palindrome);
}
