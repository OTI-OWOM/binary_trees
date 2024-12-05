#include "binary_trees.h"

/**
 *binary_tree_uncle - Finds the uncle of a node
 *@node: Pointer to the node to find the uncle for
 *Return: Pointer to the uncle node, or NULL if no uncle exists
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
/* If node is NULL or has no parent or grandparent, return NULL */
if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
return (NULL);
/* Get the grandparent */
binary_tree_t *grandparent = node->parent->parent;

/* If parent is the left child of grandparent, return right child */
if (grandparent->left == node->parent)
return (grandparent->right);

/* If parent is the right child of grandparent, return left child */
if (grandparent->right == node->parent)
return (grandparent->left);

/* This should never be reached, but included for completeness */
return (NULL);
}
