#include "binary_trees.h"

/**
 *binary_tree_is_full - Checks if a binary tree is full
 *@tree: Pointer to the root node of the tree to check
 *Return: 1 if the tree is full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
/* If tree is NULL, return 0 */
if (tree == NULL)
return (0);
/* If leaf node (no children), it's full */
if (tree->left == NULL && tree->right == NULL)
return (1);

/* if node has both children, recursively check both subtrees */
if (tree->left && tree->right)
return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

/* If node has only one child, it's not a full tree*/
return (0);
}