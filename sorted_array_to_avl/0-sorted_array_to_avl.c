#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Allocates and initializes a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
static avl_t *create_node(avl_t *parent, int value)
{
	avl_t *new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * build_avl_recursive - Recursively builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Start index of the current subarray
 * @end: End index of the current subarray
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
static avl_t *build_avl_recursive(int *array, size_t start, size_t end,
	avl_t *parent)
{
	size_t mid;
	avl_t *root;

	if (start > end)
		return (NULL);

	mid = start + (end - start) / 2;

	root = create_node(parent, array[mid]);
	if (!root)
		return (NULL);

	if (mid > start)
		root->left = build_avl_recursive(array, start, mid - 1, root);

	if (mid < end)
		root->right = build_avl_recursive(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl_recursive(array, 0, size - 1, NULL));
}
