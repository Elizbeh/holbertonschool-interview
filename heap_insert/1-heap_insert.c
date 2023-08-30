#include "binary_trees.h"

/**
 * heapify_up - Perform heapification upward after inserting a new node
 * @node: Pointer to the node to be heapified
 */
void heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        int tmp = node->n;
        node->n = node->parent->n;
        node->parent->n = tmp;
        node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;
    binary_tree_t *queue[100];
    int front = 0, rear = 0;

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    queue[rear++] = *root;

    while (front < rear)
    {
        parent = queue[front];
        front++;

        if (!parent->left)
        {
            parent->left = new_node;
            new_node->parent = parent;
            break;
        }
        else if (!parent->right)
        {
            parent->right = new_node;
            new_node->parent = parent;
            break;
        }

        queue[rear++] = parent->left;
        queue[rear++] = parent->right;
    }

    heapify_up(new_node);

    return (new_node);
}

