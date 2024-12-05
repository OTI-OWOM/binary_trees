#include "binary_trees.h"

/**
 *binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 *@tree: Pointer to the root node of the tree to count nodes
 *Return: Number of nodes with at least one child, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
/* If tree is NULL, return 0 */
if (tree == NULL)
return (0);

/* Check if node has at least one child */
if (tree->left != NULL || tree->right != NULL)
/* Count this node and recursively count nodes in subtrees */
return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

/* Node has no children */
return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
