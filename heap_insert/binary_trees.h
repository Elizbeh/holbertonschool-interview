#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Structs */
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

struct binary_tree_s
{
    int n;
    binary_tree_t *parent;
    binary_tree_t *left;
    binary_tree_t *right;
};

/* Function prototypes */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
void binary_tree_print(const binary_tree_t *);

#endif /* BINARY_TREES_H */
