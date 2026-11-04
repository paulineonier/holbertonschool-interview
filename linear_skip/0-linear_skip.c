#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @head: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer on the first node where value is located, or NULL if absent
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
	skiplist_t *express, *prev;

	if (!head)
		return (NULL);

	express = head->express;
	prev = head;

	while (express)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			express->index, express->n);

		if (express->n >= value)
			break;

		prev = express;
		express = express->express;
	}

	if (!express)
	{
		express = prev;
		while (express->next)
			express = express->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, express->index);

	while (prev && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			prev->index, prev->n);

		if (prev->n == value)
			return (prev);

		prev = prev->next;
	}

	return (NULL);
}
