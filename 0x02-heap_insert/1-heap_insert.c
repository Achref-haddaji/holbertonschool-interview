#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - check if node is root or not.
 * @node: node from tree
 *
 * Return:  1 if node is a root, otherwise 0
 * If node is NULL, return 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (!node->left && !node->right)
		return (1);
	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree of data
 *
 * Return: measures the height or 0
 *				If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (!tree)
		return (0);
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_depth - measures the depth of a binary tree
 * @tree: tree of data
 *
 * Return: measures the depth or 0
 * If tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
/**
 * _insert - function to insert node
 * @tree: pointer to tree
 * @level: level to insert node
 * @value: value of the new node
 * Return: the node inserted
 */

binary_tree_t *_insert(binary_tree_t *tree, size_t level, int value)
{
	binary_tree_t *left, *right;

	if (tree == NULL)
		return (NULL);
	if (binary_tree_depth(tree) == level)
	{
		if (binary_tree_is_root(tree))
			return (tree->left = binary_tree_node(tree, value));
		if (tree->left && !tree->right)
			return (tree->right = binary_tree_node(tree, value));
		return (NULL);
	}
	left = _insert(tree->left, level, value);
	if (!left)
		right = _insert(tree->right, level, value);
	else
		return (left);
	return (right);
}

/**
 * heap_insert - binary tree  heap max
 * @root: pointer to the root node
 * @value: value store to inserted
 * Return: the inserted node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	size_t level, i, tmp = 0;
	heap_t *node = NULL;

	if (!*root)
	{
		*root = binary_tree_node((binary_tree_t *)*root, value);
		return (*root);
	}
	level = binary_tree_height(*root);
	for (i = 0; i <= level; i++)
	{
		node = (heap_t *)_insert((binary_tree_t *)*root, i, value);
		if (node)
			break;
	}
	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->parent->n;
		node->parent->n = node->n;
		node->n = tmp;
		node = node->parent;
	}
	return (node);
}
