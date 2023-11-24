#include "binary_trees.h"

/**
 * create_binary_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Integer stored in the node
 *
 * Return: Pointer to the new node
 */
binary_tree_t *create_binary_node(binary_tree_t *parent, int value)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    if (node == NULL)
        return (NULL);

    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    node->n = value;

    return (node);
}

/**
 * create_avl_node - Creates an AVL tree node
 * @array: Pointer to the first element of the array
 * @start: Index of the first element
 * @end: Index of the last element
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the new node
 */
avl_t *create_avl_node(int *array, int start, int end, avl_t *parent)
{
    int mid;
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *node = create_binary_node(parent, array[mid]);

    if (node == NULL)
        return (NULL);

    node->left = create_avl_node(array, start, mid - 1, node);
    node->right = create_avl_node(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (array == NULL || size == 0)
        return (NULL);

    return create_avl_node(array, 0, size - 1, NULL);
}

