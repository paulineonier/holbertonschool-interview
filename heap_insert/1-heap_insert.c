#include "binary_trees.h"
#include <stdlib.h>

/* Swap values between a node and its parent */
static void swap_up(heap_t *node)
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

/* Count nodes in the heap */
static size_t heap_size(const heap_t *root)
{
    if (!root)
        return 0;
    return 1 + heap_size(root->left) + heap_size(root->right);
}

/* Find the insertion spot */
static heap_t *find_parent(heap_t *root, size_t index, size_t curr_index)
{
    if (!root)
        return NULL;
    if (curr_index == index / 2)
        return root;

    heap_t *left = find_parent(root->left, index, curr_index * 2 + 1);
    if (left)
        return left;
    return find_parent(root->right, index, curr_index * 2 + 2);
}

/* Main heap insert function */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    size_t size;

    if (!root)
        return NULL;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return NULL;

    if (!*root)
    {
        *root = new_node;
        return new_node;
    }

    size = heap_size(*root);
    parent = find_parent(*root, size + 1, 1);

    new_node->parent = parent;
    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;

    swap_up(new_node);

    return new_node;
}
