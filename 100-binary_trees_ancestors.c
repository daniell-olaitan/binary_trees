#include "binary_trees.h"

long int node_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the ancestor of the input nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *n1, *n2;
	long int d1, d2, l, i;

	if (first == NULL || second == NULL)
		return (NULL);

	d1 = node_depth(first);
	d2 = node_depth(second);
	l = d1 > d2 ? d1 - d2 : d2 - d1;
	if (d1 > d2)
	{
		n1 = first;
		n2 = second;
	}
	else
	{
		n1 = second;
		n2 = first;
	}

	for (i = l; i > 0; --i)
		n1 = n1->parent;

	while (n1)
	{
		if (n1 == n2)
			return (n1);

		n1 = n1->parent;
		n2 = n2->parent;
	}

	return (NULL);
}

/**
 * node_depth - measures the depth of a binary tree
 * @tree: pointer to a node of the tree
 *
 * Return: the depth of the tree
 */
long int node_depth(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (1 + node_depth(tree->parent));
}
