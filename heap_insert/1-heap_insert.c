#include <stdlib.h>
#include "binary_trees.h"

/**
 * struct queue_s - file pour parcours en largeur
 * @node: nœud du heap
 * @next: pointeur vers le suivant
 */
typedef struct queue_s
{
	heap_t *node;
	struct queue_s *next;
} queue_t;

/* Ajoute un élément à la file */
static void enqueue(queue_t **head, heap_t *node)
{
	queue_t *new = malloc(sizeof(queue_t));
	queue_t *tmp;

	if (!new)
		return;

	new->node = node;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return;
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

/* Retire un élément de la file */
static heap_t *dequeue(queue_t **head)
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
static heap_t *find_parent(heap_t *root)
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

/* Remonte le nœud et retourne celui qui contient la valeur insérée */
static heap_t *heapify_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: double pointeur vers la racine
 * @value: valeur à insérer
 *
 * Return: pointeur vers le nœud contenant la valeur insérée
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

	return (heapify_up(new_node));
}
