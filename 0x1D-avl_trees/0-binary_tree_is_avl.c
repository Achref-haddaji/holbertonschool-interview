#include "binary_trees.h"

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * binary_tree_height - Calculates the height of a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: The height of the tree, or 0 if tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (1 + max(binary_tree_height(tree->left),
			binary_tree_height(tree->right)));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_height, right_height, balance_factor;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	balance_factor = abs(left_height - right_height);

	if (balance_factor <= 1 &&
	    binary_tree_is_avl(tree->left) &&
	    binary_tree_is_avl(tree->right))
		return (1);

	return (0);
}
