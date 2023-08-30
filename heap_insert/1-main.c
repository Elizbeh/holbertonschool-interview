#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    heap_t *root;
    heap_t *node;

    root = NULL;
    node = heap_insert(&root, 98);   
    binary_tree_print(root);
    node = heap_insert(&root, 110);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 43);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 2);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 78);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 123);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 56);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 76);
    printf("\nInserted: %d\n", node->n);
    binary_tree_print(root);
    node = heap_insert(&root, 234);
    printf("Value inserted: %d\n", node->n);
    binary_tree_print(root);

    _binary_tree_delete(root);
    return (0);
}

