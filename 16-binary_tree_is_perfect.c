#include "binary_trees.h"

size_t _tree_height(const binary_tree_t *tree);
size_t tree_size(const binary_tree_t *tree);

/**
 * _pow - ...
 * @x: ...
 * @y: ...
 *
 * Return: ...
 */
size_t _pow(size_t x, size_t y)
{
	size_t total = x, i;

	for (i = 1; i < y; ++i)
		total = total * x;

	return (total);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t size, height;

	if (tree == NULL ||
	    (tree->left == NULL && tree->right == NULl))
		return (0);

	size = tree_size(tree);
	height = _tree_height(tree) + 1;
	if (size == _pow(2, height) - 1)
		return (1);

	return (0);
}

/**
 * _tree_height - measures the height of a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: the height of the tree
 */
size_t _tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = _tree_height(tree->left);
	right = _tree_height(tree->right);
	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * tree_size - measures the size of a binary tree
 * @tree: pointer to a node from the tree
 *
 * Return: the size of the tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_size(tree->left);
	right = tree_size(tree->right);

	return (right + left + 1);
}
