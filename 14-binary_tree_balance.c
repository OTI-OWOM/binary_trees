#include "binary_trees.h"

/**
 *tree_height - Measures the height of a binary tree
 *@tree: Pointer to the root node of the tree to measure
 *Return: Height of the tree, 0 if tree is NULL
 */
size_t tree_height(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;

/* If tree is NULL, height is 0 */
if (tree == NULL)
return (0);

/* Recursively calculate height of left subtree */
left_height = tree->left ? 1 + tree_height(tree->left) : 0;

/* Recursively calculate height of right subtree */
right_height = tree->right ? 1 + tree_height(tree->right) : 0;

/* Return the maximum height */
return (left_height > right_height ? left_height : right_height);
}

/**
 *binary_tree_balance - Measures the balance factor of a binary tree
 *@tree: Pointer to the root node of the tree to measure
 *Return: Balance factor of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left_height, right_height;

/* If tree is NULL, return 0 */
if (tree == NULL)
return (0);

/* Calculate height of left subtree */
left_height = tree->left ? (int)tree_height(tree->left) : -1;

/* Calculate height of right subtree */
right_height = tree->right ? (int)tree_height(tree->right) : -1;

/* Return balance factor (left height - right height) */
return (left_height - right_height);
}
