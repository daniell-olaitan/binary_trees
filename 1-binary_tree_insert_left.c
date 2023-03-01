#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to the parent node
 * @value: value of the node to be inserted
 * Return: pointer to the inserted node
 *
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *tmp;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL || parent == NULL)
		return (NULL);

	node->n = value;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;
	tmp = parent->left;
	if (parent->left != NULL)
	{
		parent->left = node;
		node->left = tmp;
		tmp->parent = node;
	}
	parent->left = node;

	return (node);
}
