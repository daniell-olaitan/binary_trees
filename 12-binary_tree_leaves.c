#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the number of leaves in a tree
 * @tree: pointer to the root of the tree
 *
 * Return: number of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t t = 0;

	if (tree == NULL)
		return (0);

	return (b_tree_r(tree, t));
}

/**
 * b_tree_r - ...
 * @tree: ...
 * @t: .
 *
 * Return: ...
 */
size_t b_tree_r(const binary_tree_t *tree, size_t t)
{
	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1 + t);

	return (b_tree_r(tree->left));
	return (b_tree_r(tree->right));
}
