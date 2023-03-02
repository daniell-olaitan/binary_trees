#include "binary_trees.h"

binary_tree_t *sibling(const binary_tree_t *node);

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node whose uncle is to be found
 *
 * Return: pointer to the found uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	return (sibling(parent));
}

/**
 * sibling - finds the sibling of a node
 * @node: pointer to the node whose sibling is to be found
 *
 * Return: pointer to the found sibling, NULL otherwise
 */
binary_tree_t *sibling(const binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (node == parent->left)
		return (parent->right);

	return (parent->left);
}
