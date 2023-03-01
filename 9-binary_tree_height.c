#include "binary_trees.c"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t total = 0, left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	left > right ? return (left + 1) : return(right + 1);
}
