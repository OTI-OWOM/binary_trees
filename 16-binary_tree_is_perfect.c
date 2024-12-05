#include "binary_trees.h"

/**
 *tree_depth - Calculates the depth of a node in a binary tree
 *@node: Pointer to the node to measure depth
 *Return: Depth of the node
 */

int tree_depth(const binary_tree_t *node)
{
int depth = 0;
while (node->parent)
{
depth++;
node = node->parent;
}

return (depth);
}

/**
 *is_leaf - Checks if a node is a leaf
 *@node: Pointer to the node to check
 *Return: 1 if node is a leaf, 0 otherwise
 */

int is_leaf(const binary_tree_t *node)
{
return (node->left == NULL && node->right == NULL);
}

/**
 *recursive_perfect_check - Recursively checks if tree is perfect
 *@tree: Pointer to the root node of the tree
 *@depth: Depth of the current node
 *@level: Current level of the node
 *Return: 1 if perfect, 0 otherwise
 */

int recursive_perfect_check(const binary_tree_t *tree, int depth, int level)
{
/* If tree is NULL, it's not perfect */
if (tree == NULL)
return (0);

/* If it's a leaf node, check if it's at the correct depth */
if (is_leaf(tree))
return (depth == level);

/* If node doesn't have both children, it's not perfect */
if (tree->left == NULL || tree->right == NULL)
return (0);

/* Recursively check both subtrees */
return (recursive_perfect_check(tree->left, depth, level + 1) &&
recursive_perfect_check(tree->right, depth, level + 1));
}

/**
 *binary_tree_is_perfect - Checks if a binary tree is perfect
 *@tree: Pointer to the root node of the tree to check
 *Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int depth;

/* If tree is NULL, it's not perfect */
if (tree == NULL)
return (0);

/* Calculate the depth of the tree */
depth = tree_depth(tree);

/* Check if the tree is perfect */
return (recursive_perfect_check(tree, depth, 0));
}
