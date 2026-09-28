#include <stdlib.h>
#include "binary_trees.h"

/**
 * enqueue - Ajoute un nœud à la file
 * @head: Double pointeur vers la tête de file
 * @node: Nœud à ajouter
 */
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

/**
 * dequeue - Retire un nœud de la file
 * @head: Double pointeur vers la tête de file
 *
 * Return: Pointeur vers le nœud extrait ou NULL
 */
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

/**
 * free_queue - Libère toute la file d'attente
 * @queue: Pointeur vers la file
 */
static void free_queue(queue_t *queue)
{
	queue_t *tmp;

	while (queue)
	{
		tmp = queue;
		queue = queue->next;
		free(tmp);
	}
}

/**
 * find_parent - Trouve le premier parent auquel attacher un enfant
 * @root: Pointeur vers la racine du heap
 *
 * Return: Pointeur vers le parent trouvé ou NULL
 */
static heap_t *find_parent(heap_t *root)
{
	queue_t *queue = NULL;
	heap_t *current;

	enqueue(&queue, root);

	while (queue)
	{
		current = dequeue(&queue);

		if (!current->left || !current->right)
		{
			free_queue(queue);
			return (current);
		}

		enqueue(&queue, current->left);
		enqueue(&queue, current->right);
	}

	return (NULL);
}

/**
 * heapify_up - Réorganise le tas vers le haut
 * @node: Pointeur vers le nœud inséré
 *
 * Return: Pointeur vers le nœud final après remontée
 */
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
 * @root: Double pointeur vers la racine du heap
 * @value: Valeur à stocker dans le nœud
 *
 * Return: Pointeur vers le nœud créé ou NULL en cas d'échec
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
