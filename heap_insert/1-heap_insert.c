#include <stdlib.h>
#include "binary_trees.h"

/* Structure simple de file (queue) */
typedef struct queue_s
{
	heap_t *node;
	struct queue_s *next;
} queue_t;

/* Ajoute un nœud à la file */
void enqueue(queue_t **head, heap_t *node)
{
	queue_t *new = malloc(sizeof(queue_t));

	if (!new)
		return;
	new->node = node;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return;
	}

	while ((*head)->next)
		head = &(*head)->next;
	(*head)->next = new;
}

/* Retire un nœud de la file */
heap_t *dequeue(queue_t **head)
{
	queue_t *tmp;
	heap_t *node;

	if (!head || !*head)
		return (NULL);

	tmp = *head;
	node = tmp->node;
	*head = tmp->next;
	free(tmp);
	return (node);
}

/* Trouve le premier parent incomplet */
heap_t *find_parent(heap_t *root)
{
	queue_t *queue = NULL;
	heap_t *current;

	enqueue(&queue, root);

	while (queue)
	{
		current = dequeue(&queue);

		if (!current->left || !current->right)
			return (current);

		enqueue(&queue, current->left);
		enqueue(&queue, current->right);
	}
	return (NULL);
}

/* Remonte la valeur pour respecter le Max Heap */
void heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 *
 * @root: Double pointeur vers la racine
 * @value: Valeur à insérer
 *
 * Return: Pointeur vers le nœud inséré ou NULL
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_parent(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	heapify_up(new_node);

	return (new_node);
}
