#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer to the first node
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *current;
    int *values;
    size_t size;
    size_t i;

    if (head == NULL || *head == NULL)
        return (1);

    size = 0;
    current = *head;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    values = malloc(sizeof(int) * size);
    if (values == NULL)
        return (0);

    current = *head;
    i = 0;

    while (current != NULL)
    {
        values[i] = current->n;
        i++;
        current = current->next;
    }

    for (i = 0; i < size / 2; i++)
    {
        if (values[i] != values[size - 1 - i])
        {
            free(values);
            return (0);
        }
    }

    free(values);
    return (1);
}
