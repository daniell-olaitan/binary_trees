#include "binary_trees.h"

size_t _tree_height(const binary_tree_t *tree);
int tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t right, left;
	int full;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right ==NULL)
		return (1);

	right = _tree_height(tree->right);
	left = _tree_height(tree->left);

	full = tree_is_full(tree);

	if (right - left == 0 && full)
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
 * tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->right && tree->left)
		return (tree_is_full(tree->left) &&
			tree_is_full(tree->right));

	return (0);
}
