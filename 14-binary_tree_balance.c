#include "binary_trees.h"

size_t tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: returns the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return (left - right);
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: the height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);
	if (left > right)
		return (left + 1);

	return (right + 1);
}
